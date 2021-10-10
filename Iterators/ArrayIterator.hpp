#pragma once

#include <iostream>
#include <stdexcept>
#include "Iterator.hpp"

using namespace std;

template<typename T>
class ArrayIterator : public Iterator<T> {
private:
    T *items;
    int idx = 0;
    int size;

public:
    ArrayIterator(T *list, int c, int s) : items(list), idx(c), size(s) {}

    [[nodiscard]] int getSize() const override {
        return size;
    }

    T &getCurrent() const override {
        return items[idx];
    }

    void setCurrent(T &val) {
        items[idx] = val;
    }

    void transferTo(int index) override {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        idx = index;
    }

    [[nodiscard]] int getIndex() const override {
        return idx;
    }

    ArrayIterator<T> &operator++() override {
        idx++;
        return *this;
    }

    ArrayIterator<T> &operator--() override {
        idx--;
        return *this;
    }

    ArrayIterator<T> *operator++(int) override {
        ++(*this);
        return this;
    }

    ArrayIterator<T> *operator--(int) override {
        --(*this);
        return this;
    }

    ArrayIterator<T> *operator+(int steps) const override {
        if (idx + steps < 0 || idx + steps >= size)
            throw out_of_range("Index out of range");
        return new ArrayIterator<T>(items, idx + steps, size);
    }

    ArrayIterator<T> *operator-(int steps) const override {
        if (idx - steps < 0 || idx - steps >= size)
            throw out_of_range("Index out of range");
        return new ArrayIterator<T>(items, idx - steps, size);
    }

    T &get(int index) override {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    T operator[](int index) override {
        return get(index);
    }

    void place(int index, T &val) override {
        items[index] = val;
    }

    virtual ~ArrayIterator<T>() = default;
};