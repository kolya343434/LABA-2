#include <fstream>
//#include "Interface.h"
#include "LinkedList.h"
#include "Work_With_Files.h"
#include "sorting.h"

#include <chrono>
#include <iostream>
#include <iomanip>

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
    // Объявление перегрузки оператора << как дружественной функции
    
};

ostream& operator<<(ostream& os, const Person& person) {
    os <<"\n"
        << "Person("
        << person.firstName << " " << person.lastName
        << ", Birth Year: " << person.birthYear
        << ", Height: " << fixed << setprecision(2) << person.height << "m"
        << ", Weight: " << fixed << setprecision(2) << person.weight << "kg"
        << ", ID: " << person.id << ")";
    return os;
}
*/

struct Person {
    int id;  // Уникальный идентификатор
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
            <<"Person("
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
    return a.id > b.id;
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



int main() {
    QuickSort<Person> sorterr;
    //cout<<loadTePersonstSort(4000, sorterr, &ascendingInt) << endl;

    LinkedList<Person> list_int;
    ReadNumbersFromFile("people.txt", list_int);
    /*
    list_int.Append(Person(1, "Smith", "John", 1990, 1.80, 75.0));
    list_int.Append(Person(2, "Doe", "Jane", 1985, 1.65, 65.0));
    list_int.Append(Person(3, "Brown", "Charlie", 2000, 1.75, 70.0));
    */
    list_int.Print();

    
   // QuickSort<int> sorterr;
    
   sorterr.Sort(list_int, CompareByHeight);
   list_int.Print();
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


  // Interface();

    return 0;
}



/*
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip> // Для форматирования вывода

// Структура для представления данных о человеке
struct Person {
    int id;                 // Идентификатор (от 1 до 100)
    std::string firstName;  // Имя
    std::string lastName;   // Фамилия
    int birthYear;          // Год рождения
    double height;          // Рост
    double weight;          // Вес

    // Конструктор для удобства создания объектов
    Person(int id, const std::string& firstName, const std::string& lastName, int birthYear, double height, double weight)
        : id(id), firstName(firstName), lastName(lastName), birthYear(birthYear), height(height), weight(weight) {}
};

// Функция для генерации случайного имени
std::string generateRandomName(bool isFirstName) {
    const std::string firstNames[] = { "John", "Alice", "Michael", "Sophia", "James", "Emma" };
    const std::string lastNames[] = { "Smith", "Johnson", "Brown", "Williams", "Jones", "Davis" };
    int index = rand() % 6;
    return isFirstName ? firstNames[index] : lastNames[index];
}

// Функция для генерации случайного человека
Person generateRandomPerson(int id) {
    std::string firstName = generateRandomName(true);
    std::string lastName = generateRandomName(false);
    int birthYear = 1950 + rand() % 51;      // Год рождения 1950-2000
    double height = 1.50 + (rand() % 51) / 100.0; // Рост 1.50-2.00 м
    double weight = 50.0 + static_cast<double>(rand() % 51) + (rand() % 100) / 100.0; // Вес 50-100 кг с дробной частью
    return Person(id, firstName, lastName, birthYear, height, weight);
}

// Функция для записи данных в файл
void saveToFile(const std::string& filename, const Person& person) {
    std::ofstream file(filename, std::ios::app); // Открываем файл для добавления
    if (file.is_open()) {
        file << "Person("
            << person.id << ", "
            << "\"" << person.firstName << "\", "
            << "\"" << person.lastName << "\", "
            << person.birthYear << ", "
            << std::fixed << std::setprecision(5) << person.height << ", "
            << std::fixed << std::setprecision(2) << person.weight
            << ");\n";
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    const std::string filename = "people.txt";
    int numberOfPeople = 100; // Сколько людей сгенерировать

    for (int i = 1; i <= numberOfPeople && i <= 100; ++i) { // ID от 1 до 100
        Person person = generateRandomPerson(i);
        saveToFile(filename, person);
    }

    std::cout << "Generated " << numberOfPeople << " random people and saved to " << filename << "\n";

    return 0;
}
*/