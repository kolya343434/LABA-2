#pragma once

#include <chrono>
#include <fstream>
#include <sstream>  
#include "LinkedList.h"
#include <cassert>

struct Person {
    int id;  // Уникальный идентификатор
    std::string lastName;
    std::string firstName;
    int birthYear;
    double height;
    double weight;

    // Конструктор по умолчанию
    Person() : id(0), lastName(""), firstName(""), birthYear(0), height(0.0), weight(0.0) {}

    // Пользовательский конструктор
    Person(int id, const std::string& ln, const std::string& fn, int by, double h, double w)
        : id(id), lastName(ln), firstName(fn), birthYear(by), height(h), weight(w) {}

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Person& person) {
        std::string line;
        if (std::getline(is, line)) {
            std::istringstream iss(line);
            char ignore;
            std::string fName, lName;
            int id, bYear;
            double h, w;

            // Разбираем строку, предполагая формат: Person(1, "Doe", "John", 1980, 1.75, 70)
            if (iss >> ignore >> id                           // Пропускаем 'P' и читаем id
                >> ignore >> ignore >> fName                 // Читаем первое имя в кавычках
                >> ignore >> lName                           // Читаем второе имя в кавычках
                >> ignore >> bYear >> ignore                 // Читаем год рождения и запятые
                >> h >> ignore >> w >> ignore) {             // Читаем рост, вес и закрывающую скобку ')'

                // Убираем кавычки вокруг имен
                if (!fName.empty() && fName.front() == '"' && fName.back() == '"')
                    fName = fName.substr(1, fName.size() - 2);
                if (!lName.empty() && lName.front() == '"' && lName.back() == '"')
                    lName = lName.substr(1, lName.size() - 2);

                // Присваиваем значения объекту person
                person.id = id;
                person.firstName = fName;
                person.lastName = lName;
                person.birthYear = bYear;
                person.height = h;
                person.weight = w;
            }
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "ID: " << person.id
            << ", Name: " << person.firstName << " " << person.lastName
            << ", Birth Year: " << person.birthYear
            << ", Height: " << person.height << "m"
            << ", Weight: " << person.weight << "kg";
        return os;
    }
};



// Сравнение чисел по возрастанию
inline bool ascendingInt(const int& first, const int& second) {
    return first < second; // Возвращает true, если первый меньше второго
}

// Сравнение чисел по убыванию
inline bool descendingInt(const int& first, const int& second) {
    return first > second; // Возвращает true, если первый больше второго
}

inline bool CompareByLastNames(const Person& a, const Person& b) {
    return a.lastName < b.lastName;
}

inline bool CompareById(const Person& a, const Person& b) {
    return a.id < b.id;
}

inline bool CompareByHeight(const Person& a, const Person& b) {
    return a.height < b.height;
}

inline bool ascendingInt(const long long& first, const long long& second) {
    return first < second; // Возвращает true, если первый меньше второго
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

    sorter.Sort(list, precedes); // Передаем компаратор в метод Sort

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