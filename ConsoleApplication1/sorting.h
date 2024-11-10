#pragma once

#include "ISorted.h"
#include "LinkedList.h"


template <typename T>
class InsertionSort : public ISorter<T>
{
public:
    void Sort(Sequence<T>* sequence) override
    {
        if (sequence == nullptr) return; // �������� �� nullptr
        int len = sequence->GetLength(); // ���������� -> ��� ������ ������ ����� ���������
        if (len <= 1) return; // �������� ��� ������� ������ ��� ������ ������ ��������

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


template <typename T>
class BubbleSorter : public ISorter<T>
{
public:
    void Sort(Sequence<T>* sequence) override
    {
        if (sequence == nullptr) return; // �������� �� nullptr
        int len = sequence->GetLength(); // ���������� �������� -> ��� ���������
        if (len <= 1) return; // �������� ��� ������� ������ ��� ������ � ����� ���������

        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < len - 1; i++) {
                // ��������� � ����� ��� �������������
                if (sequence->GetElement(i) > sequence->GetElement(i + 1)) {
                    sequence->Swap(sequence->GetElement(i), sequence->GetElement(i + 1));
                    swapped = true; // ���������, ��� ��������� �����
                }
            }
        } while (swapped); // ���������, ���� ���������� ������
    }
};


template <typename T>
class QuickSort : public ISorter<T>
{
public:
    void Sort(Sequence<T>* sequence) override
    {
        if (sequence == nullptr || sequence->GetLength() == 0) {
            return; // �������� �� nullptr � ������ ������������������
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
            if (sequence->GetElement(i) <= pivot) { // ��������� �� �����������
                sequence->Swap(sequence->GetElement(i), sequence->GetElement(pIndex));
                pIndex++;
            }
        }
        sequence->Swap(sequence->GetElement(pIndex), sequence->GetElement(end));
        return pIndex;
    }
};
