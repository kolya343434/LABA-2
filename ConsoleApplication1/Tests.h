#pragma once

#include <chrono>
#include <iomanip>
#include "LinkedList.h"
#include <cassert>
#include <sstream>
#include <string>
#include "Person.h" 

using std::string;
using std::quoted;
using std::istringstream;

// Функции для нагрузочного тестирования сортировок

template<typename T>
double loadTestSortSorted(int N, T& sorter, bool (*precedes)(const int& first, const int& second)) {
    DynamicArray<int> List;
    for (int i = 0; i < N; ++i) {
        List.Append(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.Sort(List, precedes);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

template<typename T>
double loadTestSortReverseSorted(int N, T& sorter, bool (*precedes)(const int& first, const int& second)) {
    DynamicArray<int> List;
    for (int i = N - 1; i >= 0; --i) {
        List.Append(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.Sort(List, precedes);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

template<typename T>
double loadTestSort(int N, T& sorter, bool (*precedes)(const int& first, const int& second)) {
    DynamicArray<int> List;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < N; ++i) {
        List.Append(rand());
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.Sort(List, precedes);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}


template<typename Sorter>
void Sorter_test1(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 12, 4, -3, 7, 0, 15, 8, 2 };
    int size = 8;
    int sortedArray[] = { -3, 0, 2, 4, 7, 8, 12, 15 };

    LinkedList<int> list(array, size);
    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test2(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 5, 3, 8, 6, 2, 9, 1 };
    int size = 7;
    int sortedArray[] = { 1, 2, 3, 5, 6, 8, 9 };

    LinkedList<int> list(array, size);
    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test3(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { -1 };
    int size = 1;
    int sortedArray[] = { -1 };

    LinkedList<int> list(array, size);
    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test4(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 10, 9, 8, 7, 6, 5 };
    int size = 6;
    int sortedArray[] = { 5, 6, 7, 8, 9, 10 };

    LinkedList<int> list(array, size);
    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test5(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int size = 100;
    LinkedList<int> list;
    for (int i = 0; i < size; i++) {
        list.Append(rand());
    }

    sorter.Sort(list, precedes);
    for (int i = 0; i < size - 1; i++) {
        assert(precedes(list.GetElement(i), list.GetElement(i + 1)) || list.GetElement(i) == list.GetElement(i + 1));
    }
}

template<typename Sorter>
void Sorter_test6(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 20, -5, 15, 0, 30, 10, 25, 5, 40, 35, 50, -10, 45, 22 };
    int size = 14;
    int sortedArray[] = { -10, -5, 0, 5, 10, 15, 20, 22, 25, 30, 35, 40, 45, 50 };

    LinkedList<int> list(array, size);
    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test7(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int size = 10;
    int sortedArray[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    LinkedList<int> list(array, size);
    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

void comparing();
void checking();
void comparingQuickSort();
void testSortsQuickSort(int n);