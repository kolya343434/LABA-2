#pragma once

#include <chrono>
#include <iomanip>
#include "LinkedList.h"
#include <cassert>
#include <sstream>
#include <string>

using namespace std;


struct Person {
    int id;
    string lastName;
    string firstName;
    int birthYear;
    double height;
    double weight;

    // Конструктор по умолчанию
    Person() : id(0), lastName(""), firstName(""), birthYear(0), height(0.0), weight(0.0) {}

    // Пользовательский конструктор
    Person(int id, const string& ln, const string& fn, int by, double h, double w)
        : id(id), lastName(ln), firstName(fn), birthYear(by), height(h), weight(w) {}

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Person& person) {
        string line;
        if (getline(is, line)) {
            size_t start = line.find('(');
            size_t end = line.find(')');
            if (start != string::npos && end != string::npos) {
                // Извлекаем содержимое внутри скобок
                string content = line.substr(start + 1, end - start - 1);
                istringstream iss(content);
                string fName, lName;
                char comma; // Для пропуска запятых
                if (iss >> person.id >> comma // ID
                    >> quoted(fName)      // First Name (в кавычках)
                    >> comma
                    >> quoted(lName)      // Last Name (в кавычках)
                    >> comma
                    >> person.birthYear   // Birth Year
                    >> comma
                    >> person.height      // Height
                    >> comma
                    >> person.weight) {   // Weight
                    person.firstName = fName;
                    person.lastName = lName;
                }
            }
        }
        return is;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "\n"
            << "Person("
            << person.id << ", "
            << "\"" << person.firstName << "\", "
            << "\"" << person.lastName << "\", "
            << person.birthYear << ", "
            << fixed << setprecision(2) << person.height << ", "
            << fixed << setprecision(2) << person.weight
            << ")";
        return os;
    }
};





inline bool ascendingInt(const int& first, const int& second) {
    return first < second;
}

inline bool descendingInt(const int& first, const int& second) {
    return first > second;
}

inline bool CompareByLastName(const Person& a, const Person& b) {
    return a.lastName < b.lastName;
}

inline bool CompareById(const Person& a, const Person& b) {
    return a.id > b.id;
}

inline bool CompareByHeight(const Person& a, const Person& b) {
    return a.height < b.height;
}

template<typename T>
double loadTestSortSorted(int N, T& sorter, bool (*precedes)(const int& first, const int& second)) {
    LinkedList<int> List;

    // Заполняем список отсортированными числами
    for (int i = 0; i < N; ++i) {
        List.Append(i); // Последовательность уже отсортирована
    }

    // Начинаем отсчет времени
    auto start = std::chrono::high_resolution_clock::now();

    // Вызываем метод сортировки через переданный объект sorter
    sorter.Sort(List, precedes);

    // Останавливаем отсчет времени
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count(); // Возвращаем длительность
}

template<typename T>
double loadTestSortReverseSorted(int N, T& sorter, bool (*precedes)(const int& first, const int& second)) {
    LinkedList<int> List;

    // Заполняем список числами в убывающем порядке
    for (int i = N - 1; i >= 0; --i) {
        List.Append(i); // Последовательность обратная отсортированной
    }

    // Начинаем отсчет времени
    auto start = std::chrono::high_resolution_clock::now();

    // Вызываем метод сортировки через переданный объект sorter
    sorter.Sort(List, precedes);

    // Останавливаем отсчет времени
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count(); // Возвращаем длительность
}



template<typename T>
double loadTestSort(int N, T& sorter, bool (*precedes)(const int& first, const int& second)) {
    LinkedList<int> List;
    
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < N; ++i) {
        List.Append(rand()); // Заполняем список случайными числами
    }

    // Начинаем отсчет времени
    auto start = std::chrono::high_resolution_clock::now();

    // Вызываем метод сортировки через переданный объект sorter
    sorter.Sort(List, precedes);

    // Останавливаем отсчет времени
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count(); // Возвращаем длительность
}
  
template<typename Sorter>
void Sorter_test1(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 6, 4, 2, 9, 10, 3, 40, -10 };
    int size = 8;
    int sortedArray[] = { -10, 2, 3, 4, 6, 9, 10, 40 };

    LinkedList<int> list(array, size);

    sorter.Sort(list, precedes); 

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test2(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = 9;
    int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    LinkedList<int> list(array, size);

    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}


template<typename Sorter>
void Sorter_test3(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 2 };
    int size = 1;
    int sortedArray[] = { 2 };

    LinkedList<int> list(array, size);

    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}


template<typename Sorter>
void Sorter_test4(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int size = 9;
    int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    LinkedList<int> list(array, size);

    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

template<typename Sorter>
void Sorter_test5(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int size = 100;
    LinkedList<int> list;

    for (int i = 0; i < size; i++) {
        list.Append(rand());
    }

    sorter.Sort(list, precedes);

    for (int i = 0; i < size - 1; i++) {
        assert(precedes(list.GetElement(i), list.GetElement(i + 1)) || list.GetElement(i) == list.GetElement(i + 1));
    }
}


template<typename Sorter>
void Sorter_test6(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { -10, 2, 3, 4, 6, 9, 10, 15, 12, 40, 30, 20, 25, 35 };
    int size = 14;
    int sortedArray[] = { -10, 2, 3, 4, 6, 9, 10, 12, 15, 20, 25, 30, 35, 40 };

    LinkedList<int> list(array, size);

    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}
template<typename Sorter>
void Sorter_test7(Sorter& sorter, bool (*precedes)(const int& first, const int& second)) {
    int array[] = { 50, 40, 30, 25, 20, 15, 10, 9, 7, 5, 3, 2, -5, -10 };
    int size = 14;
    int sortedArray[] = { -10, -5, 2, 3, 5, 7, 9, 10, 15, 20, 25, 30, 40, 50 };

    LinkedList<int> list(array, size);

    sorter.Sort(list, precedes);

    for (int i = 0; i < size; i++) {
        assert(list.GetElement(i) == sortedArray[i]);
    }
}

void comparing();
void checking();