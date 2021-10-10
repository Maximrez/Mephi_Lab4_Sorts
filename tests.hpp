#pragma once

#include <chrono>
#include <utility>
#include <cassert>
#include <random>
#include <vector>

void test_array_sequence_append(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>());
    for (int i = 0; i < n; i++) {
        seq->append(v[i]);
    }
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_sequence_append(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>());
    for (int i = 0; i < n; i++) {
        seq->append(v[i]);
    }
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_sequence_prepend(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>());
    for (int i = n - 1; i >= 0; i--) {
        seq->prepend(v[i]);
    }
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_sequence_prepend(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>());
    for (int i = n - 1; i >= 0; i--) {
        seq->prepend(v[i]);
    }
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_sequence_vector_constructor(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_sequence_vector_constructor(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_iterator_getsize(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    assert(iter->getSize() == n);
}

void test_list_iterator_getsize(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    assert(iter->getSize() == n);
}

void test_array_iterator_get(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    for (int i = 0; i < n; i++) {
        assert(iter->get(i) == v[i]);
    }
}

void test_list_iterator_get(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    for (int i = 0; i < n; i++) {
        assert(iter->get(i) == v[i]);
    }
}

void test_array_iterator_getcurrent_pp(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    for (int i = 0; i < n; i++) {
        assert(iter->getCurrent() == v[i]);
        assert(iter->getIndex() == i);
        (*iter)++;
    }
}

void test_list_iterator_getcurrent_pp(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    for (int i = 0; i < n; i++) {
        assert(iter->getCurrent() == v[i]);
        assert(iter->getIndex() == i);
        (*iter)++;
    }
}

void test_array_iterator_getcurrent_mm(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    iter->transferTo(n - 1);
    for (int i = n - 1; i >= 0; i--) {
        assert(iter->getCurrent() == v[i]);
        assert(iter->getIndex() == i);
        (*iter)--;
    }
}

void test_list_iterator_getcurrent_mm(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    iter->transferTo(n - 1);
    for (int i = n - 1; i >= 0; i--) {
        assert(iter->getCurrent() == v[i]);
        assert(iter->getIndex() == i);
        (*iter)--;
    }
}

void test_array_iterator_plus(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    Iterator<int> *new_iter = *iter + n / 2;
    for (int i = n / 2; i < n; i++) {
        assert(new_iter->getCurrent() == v[i]);
        assert(new_iter->getIndex() == i);
        (*new_iter)++;
    }
}

void test_list_iterator_plus(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    Iterator<int> *new_iter = *iter + n / 2;
    for (int i = n / 2; i < n; i++) {
        assert(new_iter->getCurrent() == v[i]);
        assert(new_iter->getIndex() == i);
        (*new_iter)++;
    }
}

void test_array_iterator_minus(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    iter->transferTo(n - 1);
    Iterator<int> *new_iter = *iter - n / 2;
    for (int i = n - 1 - n / 2; i < n; i++) {
        assert(new_iter->getCurrent() == v[i]);
        assert(new_iter->getIndex() == i);
        (*new_iter)++;
    }
}

void test_list_iterator_minus(const int n = 10000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    Iterator<int> *iter = seq->iterate();
    iter->transferTo(n - 1);
    Iterator<int> *new_iter = *iter - n / 2;
    for (int i = n - 1 - n / 2; i < n; i++) {
        assert(new_iter->getCurrent() == v[i]);
        assert(new_iter->getIndex() == i);
        (*new_iter)++;
    }
}

void test_array_mergesort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    MergeSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_mergesort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    MergeSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_insertsort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    InsertSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_insertsort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    InsertSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_quicksort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    QuickSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_quicksort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    QuickSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_shakersort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    ShakerSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_shakersort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    ShakerSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_array_heapsort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ArraySequence<int>(v));
    HeapSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}

void test_list_heapsort(const int n = 1000) {
    RandomGenerator gen(n);
    vector<int> v = gen.GenerateRandomVector();
    Sequence<int> *seq(new ListSequence<int>(v));
    HeapSorter<int> sorter;
    sorter.Sort(seq, Less);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        assert((*seq)[i] == v[i]);
    }
}