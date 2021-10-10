#pragma once

#include "Sorts/MergeSort.hpp"
#include "Sorts/InsertSort.hpp"
#include "Sorts/QuickSort.hpp"
#include "Sorts/ShakerSort.hpp"
#include "Sorts/HeapSort.hpp"


template<typename T>
class ISorter {
public:
    virtual void Sort(Sequence<T> *seq, bool (*cmp)(const T &, const T &)) = 0;
};

template<typename T>
class MergeSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*cmp)(const T &, const T &)) override {
        Iterator<int> *first = seq->iterate();
        Iterator<int> *last = *first + (seq->getSize() - 1);
        mergeSort(first, last, cmp);
    }
};

template<typename T>
class InsertSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*cmp)(const T &, const T &)) override {
        Iterator<int> *first = seq->iterate();
        insertSort(first, cmp);
    }
};

template<typename T>
class QuickSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*cmp)(const T &, const T &)) override {
        Iterator<int> *first = seq->iterate();
        Iterator<int> *last = *first + (seq->getSize() - 1);
        quickSort(first, last, cmp);
    }
};

template<typename T>
class ShakerSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*cmp)(const T &, const T &)) override {
        Iterator<int> *first = seq->iterate();
        shakerSort(first, cmp);
    }
};

template<typename T>
class HeapSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*cmp)(const T &, const T &)) override {
        Iterator<int> *first = seq->iterate();
        heapSort(first, cmp);
    }
};

template<class T>
bool Less(const T &a, const T &b) {
    return a < b;
}

template<class T>
bool Greater(const T &a, const T &b) {
    return a > b;
}