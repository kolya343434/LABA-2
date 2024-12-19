#include "Tests.h"
#include "Sorting.h"
#include <iomanip>
#include <iostream>

// ������� ��� ������������ ���������� � ������ ����������� ���������
void testSorts(int n) {
    QuickSort<int> quickSorter;
    BubbleSorter<int> bubbleSorter;
    InsertionSort<int> insertionSort;
    HeapSort<int> heapSorter; // ��������� ������������ ������������� ����������

    std::cout << "Testing with " << n << " elements:" << std::endl
        << std::setw(20) << "Bubble Sort: " << loadTestSort(n, bubbleSorter, ascendingInt) << "s" << std::endl
        << std::setw(20) << "Quick Sort: " << loadTestSort(n, quickSorter, ascendingInt) << "s" << std::endl
        << std::setw(20) << "Insertion Sort: " << loadTestSort(n, insertionSort, ascendingInt) << "s" << std::endl
        << std::setw(20) << "Heap Sort: " << loadTestSort(n, heapSorter, ascendingInt) << "s" << std::endl;
}

// ������� ��� ��������� ������������������ ����������
void comparing() {
    int n_values[] = { 1000, 2000, 3000, 4000, 5000 };
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < num_tests; ++i) {
        testSorts(n_values[i]);
    }
}

// ������� ��� �������� ������������ ����������
void checking() {
    QuickSort<int> quickSorter;
    BubbleSorter<int> bubbleSorter;
    InsertionSort<int> insertionSort;
    HeapSort<int> heapSorter;

    // ����� ��� BubbleSorter
    Sorter_test1(bubbleSorter, ascendingInt);
    Sorter_test2(bubbleSorter, ascendingInt);
    Sorter_test3(bubbleSorter, ascendingInt);
    Sorter_test4(bubbleSorter, ascendingInt);
    Sorter_test5(bubbleSorter, ascendingInt);
    Sorter_test6(bubbleSorter, ascendingInt);
    Sorter_test7(bubbleSorter, ascendingInt);

    // ����� ��� InsertionSort
    Sorter_test1(insertionSort, ascendingInt);
    Sorter_test2(insertionSort, ascendingInt);
    Sorter_test3(insertionSort, ascendingInt);
    Sorter_test4(insertionSort, ascendingInt);
    Sorter_test5(insertionSort, ascendingInt);
    Sorter_test6(insertionSort, ascendingInt);
    Sorter_test7(insertionSort, ascendingInt);

    // ����� ��� QuickSort
    Sorter_test1(quickSorter, ascendingInt);
    Sorter_test2(quickSorter, ascendingInt);
    Sorter_test3(quickSorter, ascendingInt);
    Sorter_test4(quickSorter, ascendingInt);
    Sorter_test5(quickSorter, ascendingInt);
    Sorter_test6(quickSorter, ascendingInt);
    Sorter_test7(quickSorter, ascendingInt);

    // ����� ��� HeapSort
    Sorter_test1(heapSorter, ascendingInt);
    Sorter_test2(heapSorter, ascendingInt);
    Sorter_test3(heapSorter, ascendingInt);
    Sorter_test4(heapSorter, ascendingInt);
    Sorter_test5(heapSorter, ascendingInt);
    Sorter_test6(heapSorter, ascendingInt);
    Sorter_test7(heapSorter, ascendingInt);
}
