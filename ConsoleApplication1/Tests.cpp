#include "Tests.h"
#include "Sorting.h"
#include <iomanip>
#include <iostream>


void testSorts(int n) {

    QuickSort<int> quickSorter;
    BubbleSorter<int> bubbleSorter;
    InsertionSort<int> insertionSort;
    

    std::cout << "Testing with " << n << " elements:" << std::endl
        << std::setw(20) << "Bubble Sort: " << loadTestSort(n, bubbleSorter, ascendingInt) << "s" << std::endl
        << std::setw(20) << "Quick Sort: " << loadTestSort(n, quickSorter, ascendingInt) << "s" << std::endl
        << std::setw(20) << "Insertion Sort: " << loadTestSort(n, insertionSort, ascendingInt) << "s" << std::endl;
       
}


void testSortsQuickSort(int n) {

    QuickSort<int> quickSorter;
    

    std::cout << "Testing with " << n << " elements:" << std::endl
        << std::setw(20) << "sorting sort sequence : " << loadTestSortSorted(n, quickSorter, ascendingInt) << "s" << std::endl
        << std::setw(20) << "sorting sequence: " << loadTestSort(n, quickSorter, ascendingInt) << "s" << std::endl
        << std::setw(20) << "reverce sorting sort sequence: " << loadTestSortReverseSorted(n, quickSorter, ascendingInt) << "s" << std::endl;

}


void comparing() {
    int n_values[] = { 1000, 2000, 3000, 4000, 5000 };
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < num_tests; ++i) {
        testSorts(n_values[i]);
    }
}



void comparingQuickSort() {
    int n_values[] = { 5000, 10000, 15000, 20000, 25000 };
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < num_tests; ++i) {
        
        testSortsQuickSort(n_values[i]);
    }
}


void checking() {
    QuickSort<int> quickSorter;
    BubbleSorter<int> bubbleSorter;
    InsertionSort<int> insertionSort;
   

    
    Sorter_test1(bubbleSorter, ascendingInt);
    Sorter_test2(bubbleSorter, ascendingInt);
    Sorter_test3(bubbleSorter, ascendingInt);
    Sorter_test4(bubbleSorter, ascendingInt);
    Sorter_test5(bubbleSorter, ascendingInt);
    Sorter_test6(bubbleSorter, ascendingInt);
    Sorter_test7(bubbleSorter, ascendingInt);

   
    Sorter_test1(insertionSort, ascendingInt);
    Sorter_test2(insertionSort, ascendingInt);
    Sorter_test3(insertionSort, ascendingInt);
    Sorter_test4(insertionSort, ascendingInt);
    Sorter_test5(insertionSort, ascendingInt);
    Sorter_test6(insertionSort, ascendingInt);
    Sorter_test7(insertionSort, ascendingInt);

    
    Sorter_test1(quickSorter, ascendingInt);
    Sorter_test2(quickSorter, ascendingInt);
    Sorter_test3(quickSorter, ascendingInt);
    Sorter_test4(quickSorter, ascendingInt);
    Sorter_test5(quickSorter, ascendingInt);
    Sorter_test6(quickSorter, ascendingInt);
    Sorter_test7(quickSorter, ascendingInt);


}
