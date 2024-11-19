#include "Tests.h"
#include "Sorting.h"
#include <iomanip>

// n c равномерным шагом по пяти точкам и посторит по ним крафик, график обязателен зависимость времени от клооичества данных должна проиллюстрированна графически можно даже в ексель
// перед там как показывать надо показать как мы считали
// изучить как сдклать так чтобы эксель понял что мы строкове ввели как число
//timetest



//обратно отсортированную помследовательность передать в быстрцю сортировку частично отсортировануу и просто отсортированную и по этим данным построить график
// данные должны быть большими
//ключ 


void testSorts(int n) {

	QuickSort<int> quickSorter;
	BubbleSorter<int> bubbleSorter;
	InsertionSort<int> insertionSort;

	cout << "Testing with " << n << " elements:" << endl
		<< setw(20) << "Bubble Sort: " << loadTestSort(n, bubbleSorter, ascendingInt) << "s" << endl
		<< setw(20) << "Quick Sort: " << loadTestSort(n, quickSorter, ascendingInt) << "s" << endl
		<< setw(20) << "Insertion Sort: " << loadTestSort(n, insertionSort, ascendingInt) << "s" << endl;
}
	void comparing() {

		int n = 1000;
		int a = 2000;
		int b = 3000;
		int c = 4000;
		int d = 5000;
		testSorts(n);
		testSorts(a);
		testSorts(b);
		testSorts(c);
		testSorts(d);
	
	}

	//test sorts
	// 
	//проверить на отсортированном частично отсортированном и на обратно отсортированном

	// Реализация оператора вывода
	/*
	ostream& operator<<(ostream& os, const Person& person) {
		os << "Person(" << person.firstName << " " << person.lastName
			<< ", Birth Year: " << person.birthYear
			<< ", Height: " << person.height << "m"
			<< ", Weight: " << person.weight << "kg"
			<< ", id: " << person.id << ")" << endl;
		return os;
	}*/

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
	