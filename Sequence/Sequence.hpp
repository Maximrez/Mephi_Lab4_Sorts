#pragma once

#include "../Iterators/Iterator.hpp"

template<typename T>
class Sequence {
public:
    [[nodiscard]] virtual int getSize() const = 0;

    virtual void resize(int size) = 0;

    virtual T &get(int index) const = 0;

    virtual T getFirst() const = 0;

    virtual T getLast() const = 0;

    virtual T operator[](int index) const = 0;

    virtual T &operator[](int index) = 0;

    virtual void append(T &item) = 0;

    virtual void prepend(T &item) = 0;

    virtual void insertAt(T &item, int index) = 0;

    virtual void print(std::ostream &os) const = 0;

    virtual Sequence<T> *concat(Sequence<T> &list) = 0;

    virtual Sequence<T> *getSubsequence(int startIndex, int endIndex) = 0;

    virtual Sequence<T> *clone() const = 0;

    virtual Iterator<T> *iterate() = 0;

    virtual ~Sequence<T>() = default;
};