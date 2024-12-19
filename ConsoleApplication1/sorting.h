#pragma once

#include "ISorter.h"
#include "Sequence.h"

//
// Сортировка вставками (Insertion Sort)
//
template <typename T>
class InsertionSort : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        int length = sequence.GetLength();
        if (length <= 1) return; // Если мало элементов, сортировать не нужно

        for (int i = 1; i < length; ++i) {
            T key = sequence.GetElement(i);
            int j = i - 1;

            while (j >= 0 && !precedes(sequence.GetElement(j), key)) {
                sequence.Set(j + 1, sequence.GetElement(j));
                j--;
            }
            sequence.Set(j + 1, key);
        }
    }
};

//
// Сортировка пузырьком (Bubble Sort)
//
template <typename T>
class BubbleSorter : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        int length = sequence.GetLength();
        if (length <= 1) return;

        for (int i = 0; i < length - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < length - i - 1; ++j) {
                T first = sequence.GetElement(j);
                T second = sequence.GetElement(j + 1);
                // Если порядок неверный, меняем элементы местами
                if (!precedes(first, second)) {
                    sequence.Set(j, second);
                    sequence.Set(j + 1, first);
                    swapped = true;
                }
            }
            // Если за проход не было обменов, массив уже отсортирован
            if (!swapped) return;
        }
    }
};

//
// Быстрая сортировка (QuickSort) с использованием медианы трёх
//
template <typename T>
class QuickSort : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        int length = sequence.GetLength();
        if (length <= 1) return; // Если очень мало элементов, сортировать не нужно

        QuickSortRecursive(sequence, 0, length - 1, precedes);
    }

private:
    void QuickSortRecursive(Sequence<T>& sequence, int start, int end, bool (*precedes)(const T& first, const T& second)) {
        if (start >= end) return;

        int pivotIndex = Partition(sequence, start, end, precedes);
        QuickSortRecursive(sequence, start, pivotIndex - 1, precedes);
        QuickSortRecursive(sequence, pivotIndex + 1, end, precedes);
    }

    int Partition(Sequence<T>& sequence, int start, int end, bool (*precedes)(const T& first, const T& second)) {
        int mid = start + (end - start) / 2;

        // Медиана трёх: упорядочиваем start, mid, end
        if (precedes(sequence.GetElement(mid), sequence.GetElement(start)))
            sequence.Swap(sequence.GetElement(start), sequence.GetElement(mid));
        if (precedes(sequence.GetElement(end), sequence.GetElement(start)))
            sequence.Swap(sequence.GetElement(start), sequence.GetElement(end));
        if (precedes(sequence.GetElement(end), sequence.GetElement(mid)))
            sequence.Swap(sequence.GetElement(mid), sequence.GetElement(end));

        // Теперь медиана в mid, ставим pivot в конец
        sequence.Swap(sequence.GetElement(mid), sequence.GetElement(end));
        T pivot = sequence.GetElement(end);

        int partitionIndex = start;
        for (int i = start; i < end; ++i) {
            if (precedes(sequence.GetElement(i), pivot)) {
                sequence.Swap(sequence.GetElement(i), sequence.GetElement(partitionIndex));
                partitionIndex++;
            }
        }
        sequence.Swap(sequence.GetElement(partitionIndex), sequence.GetElement(end));
        return partitionIndex;
    }
};

//
// Пирамидальная сортировка (HeapSort)
//
template <typename T>
class HeapSort : public ISorter<T> {
public:
    void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) override {
        int length = sequence.GetLength();
        if (length <= 1) return; // Если мало элементов, нет смысла сортировать

        // Построение кучи (макс-кучи)
        for (int i = length / 2 - 1; i >= 0; --i) {
            Heapify(sequence, length, i, precedes);
        }

        // Извлечение элементов из кучи по одному
        for (int i = length - 1; i > 0; --i) {
            // Перемещаем текущий корень (максимальный элемент) в конец
            sequence.Swap(sequence.GetElement(0), sequence.GetElement(i));

            // Вызываем Heapify на уменьшенной куче
            Heapify(sequence, i, 0, precedes);
        }
    }

private:
    void Heapify(Sequence<T>& sequence, int heapSize, int rootIndex, bool (*precedes)(const T& first, const T& second)) {
        int largest = rootIndex;
        int left = 2 * rootIndex + 1;
        int right = 2 * rootIndex + 2;

        // Проверяем левый дочерний узел
        if (left < heapSize && precedes(sequence.GetElement(largest), sequence.GetElement(left))) {
            largest = left;
        }

        // Проверяем правый дочерний узел
        if (right < heapSize && precedes(sequence.GetElement(largest), sequence.GetElement(right))) {
            largest = right;
        }

        // Если самый большой элемент не корень
        if (largest != rootIndex) {
            sequence.Swap(sequence.GetElement(rootIndex), sequence.GetElement(largest));

            // Рекурсивно восстанавливаем кучу
            Heapify(sequence, heapSize, largest, precedes);
        }
    }
};

inline bool ascendingInt(const int& first, const int& second) {
    return first < second;
}

inline bool descendingInt(const int& first, const int& second) {
    return first > second;
}