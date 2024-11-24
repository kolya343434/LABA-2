#pragma once

#include "ISorter.h"
#include "Sequence.h"
#include <iostream>

template <typename T>
class InsertionSort : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        int len = sequence.GetLength(); // Получаем длину последовательности
        if (len <= 1) return;           // Проверка для пустой или короткой последовательности

        for (int i = 1; i < len; i++) {
            T key = sequence.GetElement(i);    // Извлекаем текущий элемент
            int j = i - 1;

            // Перемещаем элементы, которые нарушают порядок, заданный компаратором
            while (j >= 0 && !precedes(sequence.GetElement(j), key)) {
                sequence.Set(j + 1, sequence.GetElement(j)); // Сдвигаем элемент вправо
                j--;
            }
            sequence.Set(j + 1, key); // Вставляем ключ на правильное место
        }
    }
};



template <class T>
class BubbleSorter : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        int n = sequence.GetLength(); // Получаем длину последовательности
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (!precedes(sequence.GetElement(j), sequence.GetElement(j + 1))) {
                    // Если порядок нарушен, меняем элементы местами
                    T temp = sequence.GetElement(j);
                    sequence.Set(j, sequence.GetElement(j + 1));
                    sequence.Set(j + 1, temp);
                }
            }
        }
    }
};

//#include <algorithm> // Для std::swap

template <typename T>
class QuickSort : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        if (sequence.GetLength() <= 1) {
            return; // Ничего не делаем для пустой или слишком короткой последовательности
        }

        // Вызов рекурсивной быстрой сортировки
        QuickSortRecursive(sequence, 0, sequence.GetLength() - 1, precedes);
    }

private:
    void QuickSortRecursive(Sequence<T>& sequence, int start, int end, bool (*precedes)(const T& first, const T& second)) {
        if (start >= end) return;

        // Разделение и рекурсивная сортировка
        int pivotIndex = Partition(sequence, start, end, precedes);
        QuickSortRecursive(sequence, start, pivotIndex - 1, precedes);
        QuickSortRecursive(sequence, pivotIndex + 1, end, precedes);
    }

    int Partition(Sequence<T>& sequence, int start, int end, bool (*precedes)(const T& first, const T& second)) {
        // Используем медиану трёх для выбора pivot
        int mid = start + (end - start) / 2;

        // Сравниваем и перемещаем элементы: start, mid, end
        if (precedes(sequence.GetElement(mid), sequence.GetElement(start)))
            sequence.Swap(sequence.GetElement(start), sequence.GetElement(mid));
        if (precedes(sequence.GetElement(end), sequence.GetElement(start)))
            sequence.Swap(sequence.GetElement(start), sequence.GetElement(end));
        if (precedes(sequence.GetElement(end), sequence.GetElement(mid)))
            sequence.Swap(sequence.GetElement(mid), sequence.GetElement(end));

        // После этих операций медиана находится на позиции mid
        sequence.Swap(sequence.GetElement(mid), sequence.GetElement(end)); // Ставим pivot в конец

        T pivot = sequence.GetElement(end);
        int partitionIndex = start;

        for (int i = start; i < end; i++) {
            if (precedes(sequence.GetElement(i), pivot)) {
                sequence.Swap(sequence.GetElement(i), sequence.GetElement(partitionIndex));
                partitionIndex++;
            }
        }
        sequence.Swap(sequence.GetElement(partitionIndex), sequence.GetElement(end));
        return partitionIndex;
    }
};