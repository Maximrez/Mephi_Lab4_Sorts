#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "Sequence/ArraySequence.hpp"
#include "Sequence/ListSequence.hpp"
#include "RandomGenerator.hpp"
#include "ISorter.hpp"
#include "tests.hpp"
#include "functions.hpp"

using namespace std;

int main() {

    int s1 = 0;
    while (s1 != 4) {
        cout << endl << "Select an action:" << endl << "1 - create sequence" << endl << "2 - run time comparison" << endl << "3 - run tests" << endl << "4 - exit" << endl;
        cin >> s1;
        switch (s1) {
            case 1: {
                int s4 = 0;
                while (s4 < 1 || s4 > 2) {
                    cout << endl << "Select the sequence type:" << endl << "1 - array sequence" << endl << "2 - list sequence" << endl;
                    cin >> s4;
                }
                Sequence<int> *seq;
                int s3 = 0;
                while (s3 < 1 || s3 > 2) {
                    cout << endl << "Select the way to create sequence:" << endl << "1 - from keyboard" << endl << "2 - random" << endl;
                    cin >> s3;
                    switch (s3) {
                        case 1: {
                            int n;
                            cout << "Number of elements:" << endl;
                            cin >> n;
                            cout << "Enter your elements:" << endl;
                            vector<int> vec(n);
                            for (int i = 0; i < n; i++)
                                cin >> vec[i];
                            if (s4 == 1) {
                                seq = new ArraySequence<int>(vec);
                            } else {
                                seq = new ListSequence<int>(vec);
                            }
                            break;
                        }
                        case 2: {
                            int n;
                            cout << "Number of elements:" << endl;
                            cin >> n;
                            RandomGenerator gen(n);
                            vector<int> vec = gen.GenerateRandomVector();
                            if (s4 == 1) {
                                seq = new ArraySequence<int>(vec);
                            } else {
                                seq = new ListSequence<int>(vec);
                            }
                            break;
                        }
                        default: {
                            cout << "Enter a number from the list!" << endl;
                            break;
                        }
                    }
                }
                cout << "Your sequence:" << endl;
                seq->print(cout);
                ISorter<int> *sorter;
                int s5 = 0;
                while (s5 < 1 || s5 > 5) {
                    cout << endl << "Select the sort algorithm:" << endl << "1 - HeapSort" << endl << "2 - InsertSort";
                    cout << endl << "3 - MergeSort" << endl << "4 - QuickSort" << endl << "5 - ShakerSort" << endl;
                    cin >> s5;
                    switch (s5) {
                        case 1: {
                            sorter = new HeapSorter<int>();
                            break;
                        }
                        case 2: {
                            sorter = new InsertSorter<int>();
                            break;
                        }
                        case 3: {
                            sorter = new MergeSorter<int>();
                            break;
                        }
                        case 4: {
                            sorter = new QuickSorter<int>();
                            break;
                        }
                        case 5: {
                            sorter = new ShakerSorter<int>();
                            break;
                        }
                        default: {
                            cout << "Enter a number from the list!" << endl;
                            break;
                        }
                    }
                }
                auto startTime = chrono::steady_clock::now();
                sorter->Sort(seq, Less);
                auto endTime = chrono::steady_clock::now();
                auto time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
                cout << "Your sequence:" << endl;
                seq->print(cout);
                cout << "Sorting time: ";
                if (time > 1000) {
                    cout << time / 1000 << " ms" << endl;
                } else {
                    cout << time << " mcs" << endl;
                }
                break;
            }
            case 2: {
                int s2 = 0;
                while (s2 != 8) {
                    cout << endl << "Select time test:" << endl << "1 - array random" << endl << "2 - array sorted" << endl << "3 - array reversed" << endl << "4 - list random";
                    cout << endl << "5 - list sorted" << endl << "6 - list reversed" << endl << "7 - all" << endl << "8 - back" << endl;
                    cin >> s2;
                    switch (s2) {
                        case 1: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            array_random_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;
                            break;
                        }
                        case 2: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            array_sorted_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;

                            break;
                        }
                        case 3: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            array_reversed_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;
                            break;
                        }
                        case 4: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            list_random_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;
                            break;
                        }
                        case 5: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            list_sorted_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;
                            break;
                        }
                        case 6: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            list_reversed_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;
                            break;
                        }
                        case 7: {
                            int v = 0;
                            cout << endl << "Output results?" << endl << "0 - no" << endl << "1 - yes" << endl;
                            cin >> v;
                            array_random_testing(v);
                            array_sorted_testing(v);
                            array_reversed_testing(v);
                            list_random_testing(v);
                            list_sorted_testing(v);
                            list_reversed_testing(v);
                            cout << "Comparison successfully saved to: " << GRAPHICS_DIR << endl;
                            break;
                        }
                        case 8: {
                            break;
                        }
                        default: {
                            cout << "Enter a number from the list!" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3: {
                test_array_sequence_append();
                test_list_sequence_append();
                test_array_sequence_prepend();
                test_list_sequence_prepend();
                test_array_sequence_vector_constructor();
                test_list_sequence_vector_constructor();
                test_array_iterator_getsize();
                test_list_iterator_getsize();
                test_array_iterator_get();
                test_list_iterator_get();
                test_array_iterator_getcurrent_pp();
                test_list_iterator_getcurrent_pp();
                test_array_iterator_getcurrent_mm();
                test_list_iterator_getcurrent_mm();
                test_array_iterator_plus();
                test_list_iterator_plus();
                test_array_iterator_minus();
                test_list_iterator_minus();
                test_array_mergesort();
                test_list_mergesort();
                test_array_insertsort();
                test_list_insertsort();
                test_array_quicksort();
                test_list_quicksort();
                test_array_shakersort();
                test_list_shakersort();
                test_array_heapsort();
                test_list_heapsort();

                cout << "Tests passed successfully!" << endl;
                break;
            }
            case 4 : {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
                break;
            }
        }
    }
    return 0;
}
