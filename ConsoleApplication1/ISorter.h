#pragma once

#include "Sequence.h"

//������ ������� �� 5000 ����������

//�������� ������ ,�������� 
// ������ ���� ���� ����� �������� ������������� � � ���� ������ ���� � ����������� �� ����� ����������� ����������
// ���������� �� ��������� � ���������
//������ �������� sequence/ h ���������� �� ����� �������� �� ������� ��������� ������
//���� �������� nullptr in isorted = segmentation fault ������ 
// �� ��������� ���������� ����������� ������ � 
//���� ���������� ������, ����� ��������� ����� - 

template <class T>
class ISorter {
public:
    virtual void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) = 0;

    virtual ~ISorter() {}
};


