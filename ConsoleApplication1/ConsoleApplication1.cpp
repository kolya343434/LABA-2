//#include <fstream>
#include "Interface.h"
//#include "LinkedList.h"
//#include "Work_With_Files.h"
//#include "sorting.h"

//#include <chrono>
//#include <iostream>
//#include <iomanip>
/*
template <typename Sorter>
double loadTestSort(int N, Sorter& sorter) {
    LinkedList<int> List;

    // Initialize random number generator
    std::srand(std::time(0));

    // Append N elements to the list
    for (int i = N; i >= 1; --i) {
        List.Append(i);  // Assuming Append method adds an element to the linked list
    }

    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();

    // Call the Sort method of the provided sorter
    sorter.Sort(&List);  // Assuming Sort takes a pointer to LinkedList

    // End time measurement
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}
*/



/*
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
};


ostream& operator<<(ostream& os, const Person& person) {
    os << "Person(" << person.firstName << " " << person.lastName
        << ", Birth Year: " << person.birthYear
        << ", Height: " << person.height << "m"
        << ", Weight: " << person.weight << "kg"
        << ", id: " << person.id << ")" << endl;
    return os;
}

// Сравнение чисел по возрастанию
inline bool ascendingInt(const int& first, const int& second) {
    return first < second; // Возвращает true, если первый меньше второго
}

// Сравнение чисел по убыванию
inline bool descendingInt(const int& first, const int& second) {
    return first > second; // Возвращает true, если первый больше второго
}

bool CompareByLastName(const Person& a, const Person& b) {
    return a.lastName < b.lastName;
}

bool CompareById(const Person& a, const Person& b) {
    return a.id < b.id;
}

bool CompareByHeight(const Person& a, const Person& b) {
    return a.height < b.height;
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
*/

int main() {
    //QuickSort<int> sorterr;
    //cout<<loadTestSort(4000, sorterr, &ascendingInt) << endl;

    //LinkedList<int> list_int;
   // ReadNumbersFromFile("opa.txt", list_int);
    /*
    list_int.Append(Person(1, "Smith", "John", 1990, 1.80, 75.0));
    list_int.Append(Person(2, "Doe", "Jane", 1985, 1.65, 65.0));
    list_int.Append(Person(3, "Brown", "Charlie", 2000, 1.75, 70.0));
    */
    //list_int.Print();

    
   // QuickSort<int> sorterr;
   // sorterr.Sort(list_int, ascendingInt);
        /*
        std::cout << "Сортировка по возрастанию:" << std::endl;
        for (int i = 0; i < list_int.GetLength(); i++) {
            std::cout << list_int.GetElement(i) << " ";
        }
        std::cout << std::endl;*/
   // list_int.Print();





    //QuickSort<int> quickSorter;
    //std::srand(std::time(0));

  
    //cout << loadTestSort(2000, quickSorter) << endl;
    
    /*
    LinkedList<int> numbers;
    for (int i = 1; i <= 10000; ++i) {
        numbers.Append(i);
    }
    string ops;
    ops = "poradok.txt";
    WriteSequenceToFile(ops, &numbers);

    ops = "obr_poradok.txt";
    numbers.Clear();
    for (int i = 10000; i >= 1; --i) {
        numbers.Append(i);
    }
    WriteSequenceToFile(ops, &numbers);


    ops = "chast_poradok.txt";
    numbers.Clear();
    for (int i = 1; i <= 5000; ++i) {
        numbers.Append(i); // Первые 5000 чисел - отсортированы
    }
    for (int i = 5001; i <= 10000; ++i) {
        numbers.Append(rand() % 10000); // Следующие 5000 чисел - случайные
    }
    WriteSequenceToFile(ops, &numbers);

  // setlocale(LC_ALL, "Russian");*/


   Interface();

    return 0;
}

