# pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

const int NN_START = 2e2;
const int NN_END = 5e3;
const int NN_STEP = 2e2;

const int NLOGN_START = 1e4;
const int NLOGN_END = 1e5;
const int NLOGN_STEP = 5e3;

const string &GRAPHICS_DIR = "../graphics/";

template<typename T>
void timeTest(ISorter<T> *sorter, Sequence<T> *seq, bool (*cmp)(const T &, const T &), const string &dirPath, const string &sortName, bool v = false) {
    const string &filePath = dirPath + sortName + ".txt";
    ofstream fout(filePath, ios_base::app);

    auto startTime = chrono::steady_clock::now();
    sorter->Sort(seq, cmp);
    auto endTime = chrono::steady_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    fout << seq->getSize() << " " << time / 1000 << endl;
    fout.close();
    if (v)
        cout << sortName << ": " << time / 1000 << " ms" << endl;
}


void array_random_testing(bool v = false) {
    if (v)
        cout << endl << "Array random testing:" << endl;
    string dirPath = GRAPHICS_DIR + "array/random/nn/";
    for (string sortName: {"InsertSort", "ShakerSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NN_START; n <= NN_END; n += NN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateRandomVector();

        timeTest(new InsertSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "InsertSort", v);
        timeTest(new ShakerSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "ShakerSort", v);
    }
    dirPath = GRAPHICS_DIR + "array/random/nlogn/";
    for (string sortName: {"HeapSort", "MergeSort", "QuickSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NLOGN_START; n <= NLOGN_END; n += NLOGN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateRandomVector();

        timeTest(new HeapSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "HeapSort", v);
        timeTest(new MergeSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "MergeSort", v);
        timeTest(new QuickSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "QuickSort", v);
    }
}

void array_sorted_testing(bool v = false) {
    if (v)
        cout << endl << "Array sorted testing:" << endl;
    string dirPath = GRAPHICS_DIR + "array/sorted/nn/";
    for (string sortName: {"InsertSort", "ShakerSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NN_START; n <= NN_END; n += NN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateSortedVector();

        timeTest(new InsertSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "InsertSort", v);
        timeTest(new ShakerSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "ShakerSort", v);
    }
    dirPath = GRAPHICS_DIR + "array/sorted/nlogn/";
    for (string sortName: {"HeapSort", "MergeSort", "QuickSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NLOGN_START; n <= NLOGN_END; n += NLOGN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateSortedVector();

        timeTest(new HeapSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "HeapSort", v);
        timeTest(new MergeSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "MergeSort", v);
        timeTest(new QuickSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "QuickSort", v);
    }
}

void array_reversed_testing(bool v = false) {
    if (v)
        cout << endl << "Array reversed testing:" << endl;
    string dirPath = GRAPHICS_DIR + "array/reversed/nn/";
    for (string sortName: {"InsertSort", "ShakerSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NN_START; n <= NN_END; n += NN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateReversedVector();

        timeTest(new InsertSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "InsertSort", v);
        timeTest(new ShakerSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "ShakerSort", v);
    }
    dirPath = GRAPHICS_DIR + "array/reversed/nlogn/";
    for (string sortName: {"HeapSort", "MergeSort", "QuickSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NLOGN_START; n <= NLOGN_END; n += NLOGN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateReversedVector();

        timeTest(new HeapSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "HeapSort", v);
        timeTest(new MergeSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "MergeSort", v);
        timeTest(new QuickSorter<int>(), new ArraySequence<int>(randomArray), Less, dirPath, "QuickSort", v);
    }
}

void list_random_testing(bool v = false) {
    if (v)
        cout << endl << "List random testing:" << endl;
    string dirPath = GRAPHICS_DIR + "list/random/nn/";
    for (string sortName: {"InsertSort", "ShakerSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NN_START; n <= NN_END; n += NN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateRandomVector();

        timeTest(new InsertSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "InsertSort", v);
        timeTest(new ShakerSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "ShakerSort", v);
    }
    dirPath = GRAPHICS_DIR + "list/random/nlogn/";
    for (string sortName: {"HeapSort", "MergeSort", "QuickSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NLOGN_START; n <= NLOGN_END; n += NLOGN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateRandomVector();

        timeTest(new HeapSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "HeapSort", v);
        timeTest(new MergeSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "MergeSort", v);
        timeTest(new QuickSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "QuickSort", v);
    }
}

void list_sorted_testing(bool v = false) {
    if (v)
        cout << endl << "List sorted testing:" << endl;
    string dirPath = GRAPHICS_DIR + "list/sorted/nn/";
    for (string sortName: {"InsertSort", "ShakerSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NN_START; n <= NN_END; n += NN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateSortedVector();

        timeTest(new InsertSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "InsertSort", v);
        timeTest(new ShakerSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "ShakerSort", v);
    }
    dirPath = GRAPHICS_DIR + "list/sorted/nlogn/";
    for (string sortName: {"HeapSort", "MergeSort", "QuickSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NLOGN_START; n <= NLOGN_END; n += NLOGN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateSortedVector();

        timeTest(new HeapSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "HeapSort", v);
        timeTest(new MergeSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "MergeSort", v);
        timeTest(new QuickSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "QuickSort", v);
    }
}

void list_reversed_testing(bool v = false) {
    if (v)
        cout << endl << "List reversed testing:" << endl;
    string dirPath = GRAPHICS_DIR + "list/reversed/nn/";
    for (string sortName: {"InsertSort", "ShakerSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NN_START; n <= NN_END; n += NN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateReversedVector();

        timeTest(new InsertSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "InsertSort", v);
        timeTest(new ShakerSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "ShakerSort", v);
    }
    dirPath = GRAPHICS_DIR + "list/reversed/nlogn/";
    for (string sortName: {"HeapSort", "MergeSort", "QuickSort"}) {
        const string &filePath = dirPath + sortName + ".txt";
        ofstream file(filePath, ios_base::trunc);
        file.close();
    }
    for (int n = NLOGN_START; n <= NLOGN_END; n += NLOGN_STEP) {
        if (v)
            cout << "n = " << n << endl;
        RandomGenerator gen(n);
        vector<int> randomArray = gen.GenerateReversedVector();

        timeTest(new HeapSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "HeapSort", v);
        timeTest(new MergeSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "MergeSort", v);
        timeTest(new QuickSorter<int>(), new ListSequence<int>(randomArray), Less, dirPath, "QuickSort", v);
    }
}