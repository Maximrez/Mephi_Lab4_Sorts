cmake_minimum_required(VERSION 3.19)
project(mephi_lab_sorts)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(mephi_lab_sorts main.cpp Sequence/Sequence.hpp Sequence/ListSequence.hpp Sequence/LinkedList.hpp Sequence/ArraySequence.hpp Sequence/DynamicArray.hpp ISorter.hpp Sorts/MergeSort.hpp Iterators/Iterator.hpp Iterators/ArrayIterator.hpp Iterators/ListIterator.hpp RandomGenerator.hpp Sorts/InsertSort.hpp Sorts/QuickSort.hpp Sorts/ShakerSort.hpp tests.hpp Sorts/HeapSort.hpp functions.hpp)