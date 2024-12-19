#include "LinkedList.h"  
#include <cassert>

namespace TEST_DYNAMIC_ARRAY {

    // Тестирование конструкторов DynamicArray
    void TestConstructor() {
        int initialData[] = { 1, 2, 3, 4 };
        int arraySize = 4;

        DynamicArray<int> dynArray(initialData, arraySize);

        for (int i = 0; i < arraySize; ++i) {
            assert(dynArray.GetElement(i) == initialData[i]);
        }

        DynamicArray<int> dynArrayDefault(arraySize);
        for (int i = 0; i < arraySize; ++i) {
            assert(dynArrayDefault.GetElement(i) == 0);
        }

        DynamicArray<int> dynArrayCopy(dynArray);
        for (int i = 0; i < arraySize; ++i) {
            assert(dynArrayCopy.GetElement(i) == initialData[i]);
        }
    }

    // Тестирование конструктора копирования
    void TestCopyConstructor() {
        int originalData[] = { 1, 2, 3, 4 };
        int originalSize = 4;

        DynamicArray<int> originalArray(originalData, originalSize);
        DynamicArray<int> copiedArray = originalArray;

        for (int i = 0; i < originalSize; ++i) {
            assert(originalArray.GetElement(i) == originalData[i]);
            assert(copiedArray.GetElement(i) == originalData[i]);
        }
    }

    // Тестирование доступа к элементам
    void TestGetElements() {
        int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int size = 10;

        DynamicArray<int> dynArray(data, size);

        for (int i = 0; i < size; ++i) {
            assert(dynArray.GetElement(i) == data[i]);
        }

        assert(dynArray.GetFirstElement() == data[0]);
        assert(dynArray.GetLastElement() == data[size - 1]);
    }

    // Тестирование получения подпоследовательностей
    void TestGetSubsequences() {
        int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int size = 10;

        DynamicArray<int> dynArray(data, size);

        // Получение полной подпоследовательности
        DynamicArray<int>* fullSubseq = dynArray.GetSubsequence(0, size);
        assert(dynArray.GetLength() == fullSubseq->GetLength());

        for (int i = 0; i < size; ++i) {
            assert(dynArray.GetElement(i) == fullSubseq->GetElement(i));
        }

        // Получение части последовательности
        int slice = 2;
        DynamicArray<int>* partialSubseq = dynArray.GetSubsequence(slice, size - slice);
        assert(size - 2 * slice + 1 == partialSubseq->GetLength());

        for (int i = 0; i < size - slice - 1; ++i) {
            assert(dynArray.GetElement(i + slice) == partialSubseq->GetElement(i));
        }

        // Получение одиночного элемента
        int singleIndex = 3;
        DynamicArray<int>* singleSubseq = dynArray.GetSubsequence(singleIndex, singleIndex);
        assert(singleSubseq->GetLength() == 1);
        assert(dynArray.GetElement(singleIndex) == singleSubseq->GetElement(0));
    }

    // Тестирование получения длины массива
    void TestGetLength() {
        int size = 10;
        DynamicArray<int> dynArray(size);
        assert(dynArray.GetLength() == size);
    }

    // Тестирование метода Append
    void TestAppend() {
        int initialData[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
        int initialSize = 9;
        int newElement = 9;

        DynamicArray<int> dynArray(initialData, initialSize);
        dynArray.Append(newElement);

        for (int i = 0; i < initialSize; ++i) {
            assert(dynArray.GetElement(i) == initialData[i]);
        }

        assert(dynArray.GetElement(initialSize) == newElement);
        assert(dynArray.GetLength() == (initialSize + 1));
    }

    // Тестирование метода Prepend
    void TestPrepend() {
        int initialData[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int initialSize = 9;
        int newElement = 0;

        DynamicArray<int> dynArray(initialData, initialSize);
        dynArray.Prepend(newElement);

        for (int i = 0; i < initialSize; ++i) {
            assert(dynArray.GetElement(i + 1) == initialData[i]);
        }

        assert(dynArray.GetElement(0) == newElement);
        assert(dynArray.GetLength() == (initialSize + 1));
    }

    // Тестирование метода InsertAt
    void TestInsertAt() {
        int initialData[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
        int initialSize = 9;
        int insertElement = 4;
        int insertPosition = 4;

        DynamicArray<int> dynArray(initialData, initialSize);
        dynArray.InsertAt(insertElement, insertPosition);

        for (int i = 0; i < insertPosition; ++i) {
            assert(dynArray.GetElement(i) == initialData[i]);
        }

        assert(dynArray.GetElement(insertPosition) == insertElement);

        for (int i = insertPosition + 1; i < dynArray.GetLength(); ++i) {
            assert(dynArray.GetElement(i) == initialData[i - 1]);
        }

        assert(dynArray.GetLength() == (initialSize + 1));
    }

    // Тестирование метода Union
    void TestUnion() {
        int array1[] = { 0, 1, 2, 3, 5 };
        int array2[] = { 6, 7, 8, 9 };
        int size1 = 5;
        int size2 = 4;

        DynamicArray<int> dynArray1(array1, size1);
        DynamicArray<int> dynArray2(array2, size2);
        dynArray1.Union(&dynArray2);

        for (int i = 0; i < size1; ++i) {
            assert(dynArray1.GetElement(i) == array1[i]);
        }

        for (int i = size1; i < size1 + size2; ++i) {
            assert(dynArray1.GetElement(i) == array2[i - size1]);
        }
    }

    // Тестирование итераторов
    void TestIterator() {
        int data[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
        int size = 9;
        DynamicArray<int> dynArray(data, size);

        auto beginIt = dynArray.ToBegin();
        auto endIt = dynArray.ToEnd();
        int index = 0;

        while (*beginIt != *endIt) {
            assert(dynArray.GetElement(index) == **beginIt);
            ++(*beginIt);
            ++index;
        }
    }

    // Вызов всех тестов в пространстве имён TEST_DYNAMIC_ARRAY
    void RunAllTests() {
        TestConstructor();
        TestCopyConstructor();
        TestGetElements();
        TestGetSubsequences();
        TestGetLength();
        TestAppend();
        TestPrepend();
        TestInsertAt();
        TestUnion();
        TestIterator();
    }
}

namespace TEST_LINKED_LIST {

    // Тестирование конструкторов LinkedList
    void TestConstructor() {
        int initialData[] = { 1, 2, 3, 4 };
        int arraySize = 4;

        LinkedList<int> list(initialData, arraySize);

        for (int i = 0; i < arraySize; ++i) {
            assert(list.GetElement(i) == initialData[i]);
        }

        LinkedList<int> listCopy(list);
        for (int i = 0; i < arraySize; ++i) {
            assert(listCopy.GetElement(i) == initialData[i]);
        }
    }

    // Тестирование доступа к элементам
    void TestGetElements() {
        int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int size = 10;

        LinkedList<int> list(data, size);

        for (int i = 0; i < size; ++i) {
            assert(list.GetElement(i) == data[i]);
        }

        assert(list.GetFirstElement() == data[0]);
        assert(list.GetLastElement() == data[size - 1]);
    }

    // Тестирование получения подпоследовательностей
    void TestGetSubsequences() {
        int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int size = 10;

        LinkedList<int> list(data, size);

        // Получение полной подпоследовательности
        LinkedList<int>* fullSubseq = list.GetSubsequence(0, size);
        assert(list.GetLength() == fullSubseq->GetLength());

        for (int i = 0; i < size; ++i) {
            assert(list.GetElement(i) == fullSubseq->GetElement(i));
        }

        // Получение части последовательности
        int slice = 2;
        LinkedList<int>* partialSubseq = list.GetSubsequence(slice, size - slice);
        assert(size - 2 * slice + 1 == partialSubseq->GetLength());

        for (int i = 0; i < size - slice - 1; ++i) {
            assert(list.GetElement(i + slice) == partialSubseq->GetElement(i));
        }

        // Получение одиночного элемента
        int singleIndex = 3;
        LinkedList<int>* singleSubseq = list.GetSubsequence(singleIndex, singleIndex);
        assert(singleSubseq->GetLength() == 1);
        assert(list.GetElement(singleIndex) == singleSubseq->GetElement(0));
    }

    // Тестирование получения длины списка
    void TestGetLength() {
        int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int size = 10;

        LinkedList<int> list(data, size);
        assert(list.GetLength() == size);
    }

    // Тестирование метода Append
    void TestAppend() {
        int initialData[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
        int initialSize = 9;
        int newElement = 9;

        LinkedList<int> list(initialData, initialSize);
        list.Append(newElement);

        for (int i = 0; i < initialSize; ++i) {
            assert(list.GetElement(i) == initialData[i]);
        }

        assert(list.GetElement(initialSize) == newElement);
        assert(list.GetLength() == (initialSize + 1));
    }

    // Тестирование метода Prepend
    void TestPrepend() {
        int initialData[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int initialSize = 9;
        int newElement = 0;

        LinkedList<int> list(initialData, initialSize);
        list.Prepend(newElement);

        for (int i = 0; i < initialSize; ++i) {
            assert(list.GetElement(i + 1) == initialData[i]);
        }

        assert(list.GetElement(0) == newElement);
        assert(list.GetLength() == (initialSize + 1));
    }

    // Тестирование метода InsertAt
    void TestInsertAt() {
        int initialData[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
        int initialSize = 9;
        int insertElement = 4;
        int insertPosition = 4;

        LinkedList<int> list(initialData, initialSize);
        list.InsertAt(insertElement, insertPosition);

        for (int i = 0; i < insertPosition; ++i) {
            assert(list.GetElement(i) == initialData[i]);
        }

        assert(list.GetElement(insertPosition) == insertElement);

        for (int i = insertPosition + 1; i < list.GetLength(); ++i) {
            assert(list.GetElement(i) == initialData[i - 1]);
        }

        assert(list.GetLength() == (initialSize + 1));
    }

    // Тестирование метода Union
    void TestUnion() {
        int array1[] = { 0, 1, 2, 3, 5 };
        int array2[] = { 6, 7, 8, 9 };
        int size1 = 5;
        int size2 = 4;

        LinkedList<int> list1(array1, size1);
        LinkedList<int> list2(array2, size2);

        list1.Union(&list2);

        for (int i = 0; i < size1; ++i) {
            assert(list1.GetElement(i) == array1[i]);
        }

        for (int i = size1; i < size1 + size2; ++i) {
            assert(list1.GetElement(i) == array2[i - size1]);
        }
    }

    // Тестирование итераторов
    void TestIterator() {
        int data[] = { 0, 1, 2, 3, 5, 6, 7, 8, 9 };
        int size = 9;
        LinkedList<int> list(data, size);

        auto beginIt = list.ToBegin();
        auto endIt = list.ToEnd();
        int index = 0;

        while (*beginIt != *endIt) {
            assert(list.GetElement(index) == **beginIt);
            ++(*beginIt);
            ++index;
        }
    }

    // Вызов всех тестов в пространстве имён TEST_LINKED_LIST
    void RunAllTests() {
        TestConstructor();
        TestGetElements();
        TestGetSubsequences();
        TestGetLength();
        TestAppend();
        TestPrepend();
        TestInsertAt();
        TestUnion();
        TestIterator();
    }
}
