#pragma once

template<typename T>
class Iterator {
public:
    [[nodiscard]] virtual int getSize() const = 0;

    virtual T &get(int index) = 0;

    virtual T &getCurrent() const = 0;

    virtual void setCurrent(T &val) = 0;

    [[nodiscard]] virtual int getIndex() const = 0;

    virtual T operator[](int index) = 0;

    virtual void transferTo(int index) = 0;

    virtual Iterator<T> &operator--() = 0;

    virtual Iterator<T> &operator++() = 0;

    virtual Iterator<T> *operator++(int) = 0;

    virtual Iterator<T> *operator--(int) = 0;

    virtual Iterator<T> *operator+(int steps) const = 0;

    virtual Iterator<T> *operator-(int steps) const = 0;

    virtual void place(int index, T &val) = 0;

    virtual ~Iterator<T>() = default;
};

template<typename T>
void swapCurrent(Iterator<T> *iter_a, Iterator<T> *iter_b) {
    T elem_a = iter_a->getCurrent();
    iter_a->setCurrent(iter_b->getCurrent());
    iter_b->setCurrent(elem_a);
}