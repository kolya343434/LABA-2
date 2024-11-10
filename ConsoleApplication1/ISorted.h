#pragma once
#include "Sequence.h"

template <class T>
class ISorter {
public:
    virtual void Sort(Sequence<T>* sequence) = 0;

    virtual ~ISorter() {}
};


/*
template <class T>
class ISorted {
public:
   // virtual void InsertionSort(Sequence<T>* sequence) = 0;
    //virtual void QuickSort(Sequence<T>* sequence) = 0;
    //virtual void BubbleSorter(Sequence<T>* sequence) = 0;
    virtual ~ISorted() {}
};
*/

//�������� ������ ,�������� 
// ������ ���� ���� ����� �������� ������������� � � ���� ������ ���� � ����������� �� ����� ����������� ����������
// ���������� �� ��������� � ���������
//������ �������� sequence/ h ���������� �� ����� �������� �� ������� ��������� ������
//���� �������� nullptr in isorted = segmentation fault ������ 
// �� ��������� ���������� ����������� ������ � 
//���� ���������� ������, ����� ��������� �����
