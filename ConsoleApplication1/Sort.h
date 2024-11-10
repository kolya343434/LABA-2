#pragma once

#include "ISorted.h"
#include "LinkedList.h"

// ���� � ���������� ���������� ����������
//���� ������� ������ ������� � ����� ��������  � ���,�� ��� � ���� ���������� ��� ������� ������ 
// ���� ������ �������� ����������� �� ������� � �� �������
// ���� ������� ��� ������� ���������� � ���� ������� ���� ����


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
        if (len <= 1) return; // ��������� ������� ������� ������ ��� ������ ������ ��������

        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < len - 1; i++) {
                // �������� � ��� ������������� ��������� �������.
                if (sequence->GetElement(i) > sequence->GetElement(i + 1)) {
                    sequence->Swap(sequence->GetElement(i), sequence->GetElement(i + 1));
                    swapped = true; // �������, ��� ��������� �����
                }
            }
        } while (swapped); // ����������, ���� ���������� ������
    }

    void InsertionSort(Sequence<T>* sequence) override
    {
        int len = sequence->GetLength();
        if (len <= 1) return; // ��������� ������� ������� ������ ��� ������ ������ ��������

        for (int i = 1; i < len; i++) {
            T key = sequence->GetElement(i); 
            int j = i - 1;

            // ����������� �������� ������ ����� �� ���� ������� ������
            while (j >= 0 && sequence->GetElement(j) > key) {
                sequence->Set(j + 1, sequence->GetElement(j)); // ����������� �������
                j--;
            }
            sequence->Set(j + 1, key); // �������� ���� � ���������� ���������
        }
    }
};


*/