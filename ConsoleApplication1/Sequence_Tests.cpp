
#include "LinkedList.h"  
#include <cassert>


namespace TEST_DYNAMIC_ARRAY {
	void ConstructorTests() {
		int array[] = { 1, 2, 3, 4 };
		int size = 4;

		DynamicArray<int> dynamicArray(array, size);

		for (int i = 0; i < size; i++) {
			assert(dynamicArray.GetElement(i) == array[i]);
		}

		DynamicArray<int> dynamicArray1(size);
		for (int i = 0; i < size; i++) {
			assert(dynamicArray1.GetElement(i) == 0);  
		}

		DynamicArray<int> dynamicArray2(dynamicArray);
		for (int i = 0; i < size; i++) {
			assert(dynamicArray2.GetElement(i) == array[i]);
		}
	}
	void CopyConstructorTests() {
		int array[] = { 1, 2, 3, 4 };
		int size = 4;

		DynamicArray<int> dynamicArray1(array, size);
		DynamicArray<int> dynamicArray2 = dynamicArray1;

		for (int i = 0; i < size; i++) {
			assert(dynamicArray1.GetElement(i) == array[i]);
			assert(dynamicArray2.GetElement(i) == array[i]);
		}
	}

	void GetElementsTests() {
		int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int size = 10;

		DynamicArray<int> dynamicArray(array, size);

		for (int i = 0; i < size; i++) {
			assert(dynamicArray.GetElement(i) == array[i]);
		}

		assert(dynamicArray.GetFirstElement() == array[0]);
		assert(dynamicArray.GetLastElement() == array[size - 1]);
	}

	void GetSubsequencesTests() {
		int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int size = 10;

		DynamicArray<int> dynamicArray(array, size);

		DynamicArray<int>* subsequence = dynamicArray.GetSubsequence(0, size);
		assert(dynamicArray.GetLength() == subsequence->GetLength());

		for (int i = 0; i < size; i++) {
			assert(dynamicArray.GetElement(i) == subsequence->GetElement(i));
		}

		int sliceCount = 2;
		subsequence = dynamicArray.GetSubsequence(sliceCount, size - sliceCount);
		assert(size - 2 * sliceCount + 1 == subsequence->GetLength());

		for (int i = 0; i < size - sliceCount - 1; i++) {
			assert(dynamicArray.GetElement(i + sliceCount) == subsequence->GetElement(i));
		}

		int index = 3;
		subsequence = dynamicArray.GetSubsequence(index, index);
		assert(subsequence->GetLength() == 1);
		assert(dynamicArray.GetElement(index) == subsequence->GetElement(0));
	}

	void GetLengthTests() {
		int size = 10;
		DynamicArray<int> dynamicArray(size);
		assert(dynamicArray.GetLength() == size);
	}

	void AppendTest() {
		int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		int size = 9;
		int number = 9;

		DynamicArray<int> dynamicArray(array, size);
		dynamicArray.Append(number);

		for (int i = 0; i < size; i++) {
			assert(dynamicArray.GetElement(i) == array[i]);
		}

		assert(dynamicArray.GetElement(size) == number);
		assert(dynamicArray.GetLength() == (size + 1));
	}

	void PrependTest() {
		int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int size = 9;
		int number = 0;

		DynamicArray<int> dynamicArray(array, size);
		dynamicArray.Prepend(number);

		for (int i = 0; i < size; i++) {
			assert(dynamicArray.GetElement(i + 1) == array[i]);
		}

		assert(dynamicArray.GetElement(0) == number);
		assert(dynamicArray.GetLength() == (size + 1));
	}

	void InsertAtTest() {
		int array[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
		int size = 9;
		int number = 4;
		int index = 4;

		DynamicArray<int> dynamicArray(array, size);
		dynamicArray.InsertAt(number, index);

		for (int i = 0; i < index; i++) {
			assert(dynamicArray.GetElement(i) == array[i]);
		}

		assert(dynamicArray.GetElement(index) == number);

		for (int i = index + 1; i < dynamicArray.GetLength(); i++) {
			assert(dynamicArray.GetElement(i) == array[i - 1]);
		}

		assert(dynamicArray.GetLength() == (size + 1));
	}

	void UnionTest() {
		int array1[] = { 0, 1, 2, 3, 5 };
		int array2[] = { 6, 7, 8, 9 };
		int size1 = 5;
		int size2 = 4;

		DynamicArray<int> dynamicArray1(array1, size1);
		DynamicArray<int> dynamicArray2(array2, size2);
		dynamicArray1.Union(&dynamicArray2);

		for (int i = 0; i < size1; i++) {
			assert(dynamicArray1.GetElement(i) == array1[i]);
		}

		for (int i = size1; i < size1 + size2; i++) {
			assert(dynamicArray1.GetElement(i) == array2[i - size1]);
		}
	}

	void IteratorTest() {
		int array[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
		int size = 9;
		DynamicArray<int> dynamicArray(array, size);

		auto begin = dynamicArray.ToBegin();
		auto end = dynamicArray.ToEnd();
		int i = 0;

		while (*begin != *end) {
			assert(dynamicArray.GetElement(i) == **begin);
			++(*begin);
			i++;
		}
	}
	void call() {


		ConstructorTests();
		CopyConstructorTests();
		GetElementsTests();
		GetSubsequencesTests();
		GetLengthTests();
		AppendTest();
		PrependTest();
		InsertAtTest();
		UnionTest();
		IteratorTest();
	}
}

namespace TEST_LINKED_LIST{

void ConstructorTests() {
	int array[] = { 1, 2, 3, 4 };
	int size = 4;

	LinkedList<int> list(array, size);

	for (int i = 0; i < size; i++) {
		assert(list.GetElement(i) == array[i]);
	}

	LinkedList<int> list1(list);
	for (int i = 0; i < size; i++) {
		assert(list1.GetElement(i) == array[i]);
	}
}

void GetElementsTests() {
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 10;

	LinkedList<int> list(array, size);

	for (int i = 0; i < size; i++) {
		assert(list.GetElement(i) == array[i]);
	}

	assert(list.GetFirstElement() == array[0]);
	assert(list.GetLastElement() == array[size - 1]);
}

void GetSubsequencesTests() {
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 10;

	LinkedList<int> list(array, size);

	LinkedList<int>* subsequence = list.GetSubsequence(0, size);
	assert(list.GetLength() == subsequence->GetLength());

	for (int i = 0; i < size; i++) {
		assert(list.GetElement(i) == subsequence->GetElement(i));
	}

	int sliceCount = 2;
	subsequence = list.GetSubsequence(sliceCount, size - sliceCount);
	assert(size - 2 * sliceCount + 1 == subsequence->GetLength());

	for (int i = 0; i < size - sliceCount - 1; i++) {
		assert(list.GetElement(i + sliceCount) == subsequence->GetElement(i));
	}

	int index = 3;
	subsequence = list.GetSubsequence(index, index);
	assert(subsequence->GetLength() == 1);
	assert(list.GetElement(index) == subsequence->GetElement(0));
}

void GetLengthTests() {
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 10;

	LinkedList<int> list(array, size);
	assert(list.GetLength() == size);
}

void AppendTest() {
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = 9;
	int number = 9;

	LinkedList<int> list(array, size);
	list.Append(number);

	for (int i = 0; i < size; i++) {
		assert(list.GetElement(i) == array[i]);
	}

	assert(list.GetElement(size) == number);
	assert(list.GetLength() == (size + 1));
}

void PrependTest() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 9;
	int number = 0;

	LinkedList<int> list(array, size);
	list.Prepend(number);

	for (int i = 0; i < size; i++) {
		assert(list.GetElement(i + 1) == array[i]);
	}

	assert(list.GetElement(0) == number);
	assert(list.GetLength() == (size + 1));
}

void InsertAtTest() {
	int array[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
	int size = 9;
	int number = 4;
	int index = 4;

	LinkedList<int> list(array, size);
	list.InsertAt(number, index);

	for (int i = 0; i < index; i++) {
		assert(list.GetElement(i) == array[i]);
	}

	assert(list.GetElement(index) == number);

	for (int i = index + 1; i < list.GetLength(); i++) {
		assert(list.GetElement(i) == array[i - 1]);
	}

	assert(list.GetLength() == (size + 1));
}

void UnionTest() {
	int array1[] = { 0, 1, 2, 3, 5 };
	int array2[] = { 6, 7, 8, 9 };
	int size1 = 5;
	int size2 = 4;

	LinkedList<int> list1(array1, size1);
	LinkedList<int> list2(array2, size2);

	list1.Union(&list2);

	for (int i = 0; i < size1; i++) {
		assert(list1.GetElement(i) == array1[i]);
	}

	for (int i = size1; i < size1 + size2; i++) {
		assert(list1.GetElement(i) == array2[i - size1]);
	}
}

void IteratorTest() {
	int array[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
	int size = 9;
	LinkedList<int> list(array, size);

	auto begin = list.ToBegin();
	auto end = list.ToEnd();
	int i = 0;

	while (*begin != *end) {
		assert(list.GetElement(i) == **begin);
		++(*begin);
		i++;
	}
}

void call() {
	ConstructorTests();
	GetElementsTests();
	GetSubsequencesTests();
	GetLengthTests();
	AppendTest();
	PrependTest();
	InsertAtTest();
	UnionTest();
	IteratorTest();
}
}