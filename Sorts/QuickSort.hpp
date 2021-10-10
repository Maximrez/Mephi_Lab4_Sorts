#pragma once

using namespace std;

template<typename T>
Iterator<T> *partition(Iterator<T> *first, Iterator<T> *last, bool (*cmp)(const T &, const T &)) {
    if (first->getIndex() == last->getIndex()) return first;
    Iterator<T> *iter_i = *first + 0;
    bool flag = false;

    for (Iterator<T> *iter_j = *first + 0; iter_j->getIndex() < last->getIndex(); (*iter_j)++) {
        if (cmp(iter_j->getCurrent(), last->getCurrent())) {
            if (flag) {
                (*iter_i)++;
            } else {
                flag = true;
            }
            swapCurrent(iter_i, iter_j);
        }
    }
    if (flag) {
        (*iter_i)++;
    } else {
        flag = true;
    }
    swapCurrent(iter_i, last);
    return iter_i;
}

template<typename T>
void quickSort(Iterator<T> *first, Iterator<T> *last, bool (*cmp)(const T &, const T &)) {
    if (first->getIndex() < last->getIndex()) {
        Iterator<T> *p = partition(first, last, cmp);
        if (p->getIndex() - 1 > first->getIndex())
            quickSort(first, *p - 1, cmp);
        if (p->getIndex() + 1 < last->getIndex())
            quickSort(*p + 1, last, cmp);
    }
}