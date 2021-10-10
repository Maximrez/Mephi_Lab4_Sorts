#pragma once

#include <iostream>
#include <stdexcept>
#include "Iterator.hpp"

using namespace std;

template<typename T>
struct Node {
    T value;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;

    Node(T value1, Node<T> *prev1, Node<T> *next1) : value(value1), prev(prev1), next(next1) {}

    Node(const Node<T> &node) : value(node.value), prev(node.prev), next(node.next) {}

    ~Node() = default;
};

template<typename T>
class ListIterator : public Iterator<T> {
private:
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    Node<T> *curr = nullptr;
    int leftIndex;
    int rightIndex;
    int currIndex;
    int size;

public:
    ListIterator(Node<T> *l, Node<T> *r, Node<T> *c, int lIdx, int rIdx, int cIdx, int s) : left(l), right(r), curr(c), leftIndex(lIdx), rightIndex(rIdx), currIndex(cIdx), size(s) {}

    [[nodiscard]] int getSize() const override {
        return size;
    }

    T &getCurrent() const override {
        return curr->value;
    }

    void setCurrent(T &val) {
        curr->value = val;
    }

    void transferTo(int index) override {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");

        int currToIndex = abs(currIndex - index);
        int leftToIndex = abs(leftIndex - index);
        int rightToIndex = abs(rightIndex - index);

        if (currToIndex <= leftToIndex && currToIndex <= rightToIndex) {
            if (currIndex < index)
                for (int i = currIndex; i < index; i++)
                    curr = curr->next;
            else
                for (int i = currIndex; i > index; i--)
                    curr = curr->prev;
        } else {
            if (leftToIndex <= currToIndex && leftToIndex <= rightToIndex) {
                curr = new Node<T>(*left);
                if (leftIndex < index)
                    for (int i = leftIndex; i < index; i++)
                        curr = curr->next;
                else
                    for (int i = leftIndex; i > index; i--)
                        curr = curr->prev;
            } else {
                curr = new Node<T>(*right);
                if (rightIndex < index)
                    for (int i = rightIndex; i < index; i++)
                        curr = curr->next;
                else
                    for (int i = rightIndex; i > index; i--)
                        curr = curr->prev;
            }
        }
        currIndex = index;
    }

    [[nodiscard]] int getIndex() const override {
        return currIndex;
    }

    ListIterator<T> &operator++() override {
        curr = curr->next;
        currIndex++;
        return *this;
    }

    ListIterator<T> &operator--() override {
        curr = curr->prev;
        currIndex--;
        return *this;
    }

    ListIterator<T> *operator++(int) override {
        ++(*this);
        return this;
    }

    ListIterator<T> *operator--(int) override {
        --(*this);
        return this;
    }

    ListIterator<T> *operator+(int steps) const override {
        if (currIndex + steps >= 0 && currIndex + steps < size) {
            Node<T> *curr2 = curr;
            if (steps > 0)
                for (int i = 0; i < steps; i++)
                    curr2 = curr2->next;
            else
                for (int i = 0; i > steps; i--)
                    curr2 = curr2->prev;
            return new ListIterator<T>(left, right, curr2, leftIndex, rightIndex, currIndex + steps, size);
        } else
            throw out_of_range("Index out of range");
    }

    ListIterator<T> *operator-(int steps) const override {
        if (currIndex - steps >= 0 && currIndex - steps < size) {
            auto curr2 = new Node<T>(*curr);
            if (steps > 0)
                for (int i = 0; i < steps; i++)
                    curr2 = curr2->prev;
            else
                for (int i = 0; i > steps; i--)
                    curr2 = curr2->next;
            return new ListIterator<T>(left, right, curr2, leftIndex, rightIndex, currIndex - steps, size);
        } else
            throw out_of_range("Index out of range");
    }

    T &get(int index) override {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        if (abs(leftIndex - index) < abs(rightIndex - index)) {
            if (index <= leftIndex) {
                for (leftIndex; leftIndex > index; leftIndex--) left = left->prev;
                return left->value;
            } else {
                for (leftIndex; leftIndex < index; leftIndex++) left = left->next;
                return left->value;
            }
        } else {
            if (index <= rightIndex) {
                for (rightIndex; rightIndex > index; rightIndex--) right = right->prev;
                return right->value;
            } else {
                for (rightIndex; rightIndex < index; rightIndex++) right = right->next;
                return right->value;
            }
        }
    }

    T operator[](int index) override {
        return get(index);
    }

    void place(int index, T &val) override {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        if (abs(leftIndex - index) < abs(rightIndex - index)) {
            if (index <= leftIndex) {
                for (leftIndex; leftIndex > index; leftIndex--) left = left->prev;
                left->value = val;
            } else {
                for (leftIndex; leftIndex < index; leftIndex++) left = left->next;
                left->value = val;
            }
        } else {
            if (index <= rightIndex) {
                for (rightIndex; rightIndex > index; rightIndex--) right = right->prev;
                right->value = val;
            } else {
                for (rightIndex; rightIndex < index; rightIndex++) right = right->next;
                right->value = val;
            }
        }
    }

    virtual ~ListIterator<T>() = default;
};