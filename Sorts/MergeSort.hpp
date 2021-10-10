#pragma once

using namespace std;

template<typename T>
void merge(Iterator<T> *first, Iterator<T> *middle, Iterator<T> *last, bool (*cmp)(const T &, const T &)) {
    int size = 0;
    vector<T> ans(last->getIndex() - first->getIndex() + 1);
    Iterator<T> *iter_i = *first + 0, *iter_j = *middle + 1;

    while (iter_i->getIndex() <= middle->getIndex() && iter_j->getIndex() <= last->getIndex()) {
        if (cmp(iter_i->getCurrent(), iter_j->getCurrent())) {
            ans[size++] = iter_i->getCurrent();
            (*iter_i)++;
        } else {
            ans[size++] = iter_j->getCurrent();
            (*iter_j)++;
        }
    }

    while (iter_i->getIndex() <= middle->getIndex()) {
        ans[size++] = iter_i->getCurrent();
        (*iter_i)++;
    }
    while (iter_j->getIndex() <= last->getIndex()) {
        ans[size++] = iter_j->getCurrent();
        (*iter_j)++;
    }


    size = 0;
    Iterator<T> *new_iter_i = *first + 0;
    while (new_iter_i->getIndex() <= last->getIndex()) {
        new_iter_i->setCurrent(ans[size++]);
        (*new_iter_i)++;
    }
}

template<typename T>
void mergeSort(Iterator<T> *first, Iterator<T> *last, bool (*cmp)(const T &, const T &)) {
    if (first->getIndex() < last->getIndex()) {
        Iterator<T> *middle = *first + (last->getIndex() - first->getIndex()) / 2;
        mergeSort<T>(first, middle, cmp);
        mergeSort<T>(*middle + 1, last, cmp);
        merge<T>(first, middle, last, cmp);
    }
}