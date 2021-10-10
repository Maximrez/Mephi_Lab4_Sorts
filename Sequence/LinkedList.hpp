#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include "../Iterators/ListIterator.hpp"

using namespace std;

template<typename T>
class LinkedList {
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
    int list_size;

public:
    LinkedList() : first(nullptr), last(nullptr), list_size(0) {}

    LinkedList(T *list, int size) {
        list_size = 0;
        for (int i = 0; i < size; i++)
            append(list[i]);
    }

    explicit LinkedList(const vector<T> &vec) {
        list_size = 0;
        for (int i = 0; i < vec.size(); i++) {
            T item = vec[i];
            append(item);
        }
    }

    LinkedList(const LinkedList<T> &list) {
        list_size = list.getSize();
        for (Node<T> *i = list.first; i != nullptr; i = i->next) {
            auto *item = new Node<T>(i->value, last, nullptr);
            if (first == nullptr)
                first = item;
            if (last != nullptr)
                last->next = item;
            last = item;
        }
    }

    T getFirst() const {
        if (first == nullptr)
            throw out_of_range("Index out of range");
        return first->value;
    }

    T getLast() const {
        if (last == nullptr)
            throw out_of_range("Index out of range");
        return last->value;
    }

    [[nodiscard]] int getSize() const {
        return list_size;
    }

    void resize(int size) {
        if (size < 0)
            throw bad_array_new_length();
        int old_size = getSize();
        if (size <= old_size) {
            while (old_size != size) {
                Node<T> *item = last;
                last = last->prev;
                delete item;
                old_size--;
            }
            last->next = nullptr;
        } else {
            while (old_size != size) {
                auto *item = new Node<T>(0, last, nullptr);
                last->next = item;
                last = item;
                old_size++;
            }
        }
        list_size = size;
    }

    T &get(int index) const {
        if (index < 0 || index >= getSize())
            throw out_of_range("Index out of range");
        int j = 0;
        for (Node<T> *i = first; i != nullptr; i = i->next) {
            if (j == index)
                return i->value;
            j++;
        }
    }

    T operator[](int index) const {
        return get(index);
    }

    T &operator[](int index) {
        return get(index);
    }

    void append(T &item) {
        auto *elem = new Node<T>(item, last, nullptr);
        if (first == nullptr)
            first = elem;
        if (last != nullptr)
            last->next = elem;
        last = elem;
        list_size++;
    }

    void prepend(T &item) {
        auto *elem = new Node<T>(item, nullptr, first);
        if (first != nullptr)
            first->prev = elem;
        first = elem;
        if (last == nullptr)
            last = elem;
        list_size++;
    }

    void insertAt(T &item, int index) {
        if (index < 0 || index > getSize())
            throw out_of_range("Index out of range");
        if (getSize() == 0) {
            first = new Node<T>(item, nullptr, nullptr);
            last = new Node<T>(item, nullptr, nullptr);
        } else {
            if (index == 0) {
                auto *elem = new Node<T>(item, nullptr, first);
                first->prev = elem;
                first = elem;
            } else {
                Node<T> *i = first;
                for (int j = 0; j < index - 1; j++)
                    i = i->next;
                auto *elem = new Node<T>(item, i, i->next);
                i->next = elem;
                if (elem->next == nullptr) {
                    last = elem;
                } else {
                    elem->next->prev = elem;
                }
            }
        }
        list_size++;
    }

    void print(ostream &os) const {
        os << "[";
        if (first != nullptr) {
            os << first->value;
            for (Node<T> *i = first->next; i != nullptr; i = i->next) {
                os << ", " << i->value;
            }
        }
        os << "]" << endl;
    }

    Iterator<T> *iterate() {
        return new ListIterator<T>(first, last, first, 0, list_size - 1, 0, list_size);
    }

    ~LinkedList() {
        while (first != nullptr) {
            Node<T> *item = first;
            first = first->next;
            delete item;
        }
        first = nullptr;
        last = nullptr;
    }

};