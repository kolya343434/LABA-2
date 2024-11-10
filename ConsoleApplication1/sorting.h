#pragma once

#include "ISorted.h"
#include "LinkedList.h"


template <typename T>
class InsertionSort : public ISorter<T>
{
public:
    void Sort(Sequence<T>* sequence) override
    {
        if (sequence == nullptr) return; // Проверка на nullptr
        int len = sequence->GetLength(); // Используем -> для вызова метода через указатель
        if (len <= 1) return; // Проверка для пустого списка или списка одного элемента

        for (int i = 1; i < len; i++) {
            T key = sequence->GetElement(i);
            int j = i - 1;

            // Переместить элементы больше ключа на одну позицию вперед
            while (j >= 0 && sequence->GetElement(j) > key) {
                sequence->Set(j + 1, sequence->GetElement(j)); // Переместить элемент
                j--;
            }
            sequence->Set(j + 1, key); // Вставить ключ в правильное положение
        }
    }
};


template <typename T>
class BubbleSorter : public ISorter<T>
{
public:
    void Sort(Sequence<T>* sequence) override
    {
        if (sequence == nullptr) return; // Проверка на nullptr
        int len = sequence->GetLength(); // Используем оператор -> для указателя
        if (len <= 1) return; // Проверка для пустого списка или списка с одним элементом

        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < len - 1; i++) {
                // Сравнение и обмен при необходимости
                if (sequence->GetElement(i) > sequence->GetElement(i + 1)) {
                    sequence->Swap(sequence->GetElement(i), sequence->GetElement(i + 1));
                    swapped = true; // Указываем, что произошел обмен
                }
            }
        } while (swapped); // Повторяем, пока происходят замены
    }
};


template <typename T>
class QuickSort : public ISorter<T>
{
public:
    void Sort(Sequence<T>* sequence) override
    {
        if (sequence == nullptr || sequence->GetLength() == 0) {
            return; // Проверка на nullptr и пустую последовательность
        }
        QuickSorter(sequence, 0, sequence->GetLength() - 1);
    }

private:
    void QuickSorter(Sequence<T>* sequence, int start, int end)
    {
        if (start >= end) {
            return;
        }
        int pivot = partition(sequence, start, end);
        QuickSorter(sequence, start, pivot - 1);
        QuickSorter(sequence, pivot + 1, end);
    }

    int partition(Sequence<T>* sequence, int start, int end)
    {
        T pivot = sequence->GetElement(end);
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if (sequence->GetElement(i) <= pivot) { // Сравнение по возрастанию
                sequence->Swap(sequence->GetElement(i), sequence->GetElement(pIndex));
                pIndex++;
            }
        }
        sequence->Swap(sequence->GetElement(pIndex), sequence->GetElement(end));
        return pIndex;
    }
};
