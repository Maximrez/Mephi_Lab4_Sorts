#pragma once

#include "DynamicArray.hpp"
#include "Sequence.hpp"

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> items;
public:
    ArraySequence() : items() {}

    ArraySequence(T *list, int size) : items(list, size) {}

    ArraySequence(const ArraySequence<T> &list) : items() {
        for (int i = 0; i < list.getSize(); i++)
            append(list.get(i));
    }

    explicit ArraySequence(const vector<T> &vec) : items(vec)
    {}

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
        return items[0];
    }

    T getLast() const override {
        return items[items.getSize() - 1];
    }

    T operator[](int index) const override {
        return items[index];
    }

    T &operator[](int index) override {
        return items[index];
    }

    void append(T &item) override {
        int size = items.getSize();
        items.resize(size + 1);
        items[size] = item;
    }

    void prepend(T &item) override {
        int size = items.getSize();
        items.resize(size + 1);
        for (int i = size; i > 0; i--)
            items[i] = items[i - 1];
        items[0] = item;
    }

    void insertAt(T &item, int index) override {
        int size = items.getSize();
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");
        items.resize(size + 1);
        for (int i = size; i > index; i--)
            items[i] = items[i - 1];
        items[index] = item;
    }

    void print(ostream &os) const override {
        os << "[";
        for (int i = 0; i < getSize() - 1; i++) {
            os << items[i] << ", ";
        }
        if (getSize() >= 1) os << items[getSize() - 1];
        os << "]" << endl;
    }

    Sequence<T> *concat(Sequence<T> &list) override {
        auto *concatenated = new ArraySequence<T>;
        concatenated->items.resize(getSize() + list.getSize());
        for (int i = 0; i < items.getSize(); i++)
            concatenated->items[i] = items[i];
        for (int i = 0; i < list.getSize(); i++)
            concatenated->items[i + items.getSize()] = list[i];
        return concatenated;
    }

    Sequence<T> *getSubsequence(int startIndex, int endIndex) override {
        auto *sub = new ArraySequence<T>;
        sub->items.resize(endIndex - startIndex);
        for (int i = startIndex; i < endIndex; i++)
            sub->items[i - startIndex] = items[i];
        return sub;
    }

    Sequence<T> *clone() const override {
        auto *new_items = new ArraySequence<T>();
        new_items->resize(getSize());
        for (int i = 0; i < getSize(); i++)
            (*new_items)[i] = items.get(i);
        return new_items;
    }

    Iterator<T> *iterate() override {
        return items.iterate();
    }

    virtual ~ArraySequence<T>() = default;
};