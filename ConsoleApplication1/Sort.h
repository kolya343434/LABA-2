#pragma once

#include "ISorted.h"
#include "LinkedList.h"

// надо в сортировку передавать компаратор
//надо грузить индекс позиция в файле элемента  и вес,то что я буду сравнивать для больших файлов 
// наша задача показать зависимость на графике а не циферки
// надо убедить что быстрая сортировка в разы быстрее бабл сорт


/*
template <class T>
class Sort : public ISorted<T> {
private:

    int Separation(int low, int high, Sequence<T>* sequence)
    {
        T pivot = sequence->GetElement(high);
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (sequence->GetElement(j) <= pivot)
            {
                i++;
                sequence->Swap(sequence->GetElement(i), sequence->GetElement(j));
            }
        }

        i += 1;
        sequence->Swap(sequence->GetElement(i), sequence->GetElement(high));

        return i;
    }

    void QuickSort(int low, int high, Sequence<T>* sequence)
    {
        if (low < high)
        {
            int pivot = Separation(low, high, sequence);
            QuickSort(low, pivot - 1, sequence);
            QuickSort(pivot + 1, high, sequence);
        }
    }

public:

    void QuickSort(Sequence<T>* sequence) override
    {
        QuickSort(0, sequence->GetLength() - 1, sequence);
    }

    void BubbleSorter(Sequence<T>* sequence) override
    {
        int len = sequence->GetLength();
        if (len <= 1) return; // Проверьте наличие пустого списка или списка одного элемента

        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < len - 1; i++) {
                // Сравните и при необходимости поменяйте местами.
                if (sequence->GetElement(i) > sequence->GetElement(i + 1)) {
                    sequence->Swap(sequence->GetElement(i), sequence->GetElement(i + 1));
                    swapped = true; // Укажите, что произошел обмен
                }
            }
        } while (swapped); // Повторяйте, пока происходят замены
    }

    void InsertionSort(Sequence<T>* sequence) override
    {
        int len = sequence->GetLength();
        if (len <= 1) return; // Проверьте наличие пустого списка или списка одного элемента

        for (int i = 1; i < len; i++) {
            T key = sequence->GetElement(i); 
            int j = i - 1;

            // Переместить элементы больше ключа на одну позицию вперед
            while (j >= 0 && sequence->GetElement(j) > key) {
                sequence->Set(j + 1, sequence->GetElement(j)); // Переместить элемент
                j--;
            }
            sequence->Set(j + 1, key); // Вставьте ключ в правильное положение
        }
    }
};


*/