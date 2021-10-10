#pragma once

#include "LinkedList.hpp"
#include "Sequence.hpp"

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> items;

public:
    ListSequence() : items() {}

    ListSequence(T *list, int size) : items(list, size) {}

    ListSequence(const ListSequence<T> &list) : items() {
        for (int i = 0; i < list.getSize(); i++)
            items.append(list.get(i));
    }

    explicit ListSequence(const vector<T> &vec) : items(vec) {}

    [[nodiscard]] int getSize() const override {
        return items.getSize();
    }

    void resize(int size) override {
        items.resize(size);
    }

    T &get(int index) const override {
        return items.get(index);
    }

    T getFirst() const override {
        return items.getFirst();
    }

    T getLast() const override {
        return items.getLast();
    }

    T operator[](int index) const override {
        return items[index];
    }

    T &operator[](int index) override {
        return items[index];
    }

    void append(T &item) override {
        items.append(item);
    }

    void prepend(T &item) override {
        items.prepend(item);
    }

    void insertAt(T &item, int index) override {
        items.insertAt(item, index);
    }

    void print(ostream &os) const override {
        items.print(os);
    }

    Sequence<T> *concat(Sequence<T> &list) override {
        auto *concatenated = new ListSequence<T>(*this);
        for (int i = 0; i < list.getSize(); i++) {
            concatenated->append(list[i]);
        }
        return concatenated;
    }

    Sequence<T> *getSubsequence(int startIndex, int endIndex) override {
        auto *sub = new ListSequence<T>;
        for (int i = startIndex; i < endIndex; i++)
            sub->append(items[i]);
        return sub;
    }

    Sequence<T> *clone() const override {
        auto *new_items = new ListSequence<T>();
        for (int i = 0; i < getSize(); i++)
            new_items->append(items.get(i));
        return new_items;
    }

    Iterator<T> *iterate() override {
        return items.iterate();
    }

    virtual ~ListSequence<T>() = default;
};