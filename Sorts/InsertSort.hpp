#pragma once

using namespace std;

template<typename T>
void insertSort(Iterator<T> *iter, bool (*cmp)(const T &, const T &)) {
    for (int i = 1; i < iter->getSize(); i++) {
        T elemR = iter->get(i);
        iter->transferTo(i);
        while (iter->getIndex() > 0) {
            (*iter)--;
            T elemL = iter->getCurrent();
            if (cmp(elemR, elemL)) {
                iter->setCurrent(elemR);
                (*iter)++;
                iter->setCurrent(elemL);
                (*iter)--;
            } else {
                break;
            }
            elemR = iter->getCurrent();
        }
    }
}