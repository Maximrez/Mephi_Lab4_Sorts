#pragma once

using namespace std;

template<typename T>
void shakerSort(Iterator<T> *first, bool (*cmp)(const T &, const T &)) {
    if (first->getSize() == 1) return;
    int l = -1;
    int r = first->getSize();
    Iterator<T> *next = *first + 1;
    while (l < r) {
        while (next->getIndex() < r - 1) {
            if (cmp(next->getCurrent(), first->getCurrent())) {
                swapCurrent(first, next);
            }
            (*first)++;
            (*next)++;
        }
        if (cmp(next->getCurrent(), first->getCurrent())) {
            swapCurrent(first, next);
        }
        r--;
        while (first->getIndex() > l + 1) {
            if (cmp(next->getCurrent(), first->getCurrent())) {
                swapCurrent(first, next);
            }
            (*first)--;
            (*next)--;
        }
        if (cmp(next->getCurrent(), first->getCurrent())) {
            swapCurrent(first, next);
        }
        l++;
    }
}