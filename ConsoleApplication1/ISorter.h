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


// inline bool precedesInt(const int& first, const int& second) { return first < second; }


//���������� ����������� ���������� , bool (precedes*)(conat T &first, conat T &second)

/*

inline bool ascendingInt(const int& first, const int& second) { return first < second; }
inline bool descendingInt(const int& first, const int& second) { return first > second; }

bool personCompare(const Person&, const Person&);*/