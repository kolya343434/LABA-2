#pragma once


#include <chrono>
#include <fstream>
#include <sstream>  

using namespace std;

    struct Person {

        string lastName;
        string firstName;
        int birthYear;
        double height;
        double weight;
        Person() : lastName(""), firstName(""), birthYear(0), height(0.0), weight(0.0) {}

        Person(const string& ln, const string& fn, int by, double h, double w)
            : lastName(ln), firstName(fn), birthYear(by), height(h), weight(w) {}
      
        friend std::istream& operator>>(std::istream& is, Person& person) {
            std::string line;
            if (std::getline(is, line)) {
                std::istringstream iss(line);
                char ignore;
                std::string fName, lName;
                int bYear;
                double h, w;

                // Разбираем строку, предполагая формат: Person("Doe", "John", 1980, 1.75, 70)
                if (iss >> ignore >> ignore                    // Пропускаем 'P' и '('
                    >> std::ws >> ignore >> fName              // Читаем первое имя в кавычках
                    >> ignore >> lName                         // Читаем второе имя в кавычках
                    >> ignore >> bYear >> ignore               // Читаем год рождения и запятые
                    >> h >> ignore >> w >> ignore) {           // Читаем рост, вес и закрывающую скобку ')'

                    // Убираем кавычки вокруг имен
                    if (!fName.empty() && fName.front() == '"' && fName.back() == '"')
                        fName = fName.substr(1, fName.size() - 2);
                    if (!lName.empty() && lName.front() == '"' && lName.back() == '"')
                        lName = lName.substr(1, lName.size() - 2);

                    // Присваиваем значения объекту person
                    person.firstName = fName;
                    person.lastName = lName;
                    person.birthYear = bYear;
                    person.height = h;
                    person.weight = w;
                }

            }
            return is;
        }
     

        bool operator<(const Person other) const;
        bool operator>(const Person other) const;
        bool operator==(const Person other) const;
        bool operator<=(const Person other) const;
        bool operator>=(const Person other) const;
        bool operator!=(const Person other) const;

    };

    // Объявление оператора вывода
    ostream& operator<<(ostream& os, const Person& person);

   //void  random_huge_data();

   void BubbleSorter_test1();
   void BubbleSorter_test2();
   void BubbleSorter_test3();
   void BubbleSorter_test4();
   void BubbleSorter_test5();

   void InsertionSort_test1();
   void InsertionSort_test2();
   void InsertionSort_test3();
   void InsertionSort_test4();
   void InsertionSort_test5();

   void QuickSort_test1();
   void QuickSort_test2();
   void QuickSort_test3();
   void QuickSort_test4();
   void QuickSort_test5();

   void comparing();

   double loadTestINSERTION(int N);
   double loadTestBUBLE(int N);
   double loadTestQUICK(int N);

   void checking();