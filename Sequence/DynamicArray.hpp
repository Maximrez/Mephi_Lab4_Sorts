#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include "../Iterators/ArrayIterator.hpp"

using namespace std;

template<typename T>
class DynamicArray {
private:
    int list_size;
    int capacity;
    T *items;
public:
    DynamicArray() : list_size(0), capacity(0) {}

    DynamicArray(T *list, int size) {
        if (size < 0)
            throw bad_alloc();
        items = new T[size];
        list_size = size;
        capacity = size;
        for (int i = 0; i < size; i++)
            items[i] = list[i];
    }

    explicit DynamicArray(const vector<T> vec) : list_size(vec.size()), capacity(vec.size()) {
        items = new T[vec.size()];
        for (int i = 0; i < vec.size(); i++)
            items[i] = vec[i];
    }

    DynamicArray(const DynamicArray<T> &list) : list_size(list.list_size), capacity(list.capacity), items(list.items) {}

    [[nodiscard]] int getSize() const {
        return list_size;
    }

    void resize(int size) {
        if (size < 0)
            throw bad_array_new_length();
        if (size > capacity) {
            int new_capacity = size * 2;
            T *new_items = new T[new_capacity];
            memcpy(new_items, items, sizeof(T) * list_size);
//            delete[] items;
            items = new_items;
            capacity = new_capacity;
        }
        list_size = size;
    }

    T &get(int index) const {
        if (index < 0 || index >= list_size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    T operator[](int index) const {
        if (index < 0 || index >= list_size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    T &operator[](int index) {
        if (index < 0 || index >= list_size)
            throw out_of_range("Index out of range");
        return items[index];
    }

    Iterator<T> *iterate() {
        return new ArrayIterator<T>(items, 0, list_size);
    }

    ~DynamicArray<T>() = default;
};