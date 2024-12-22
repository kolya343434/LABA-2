#pragma once


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

struct Person {
    int id;
    std::string lastName;
    std::string firstName;
    int birthYear;
    double height;
    double weight;

    
    Person() : id(0), lastName(""), firstName(""), birthYear(0), height(0.0), weight(0.0) {}

    
    Person(int id, const std::string& ln, const std::string& fn, int by, double h, double w)
        : id(id), lastName(ln), firstName(fn), birthYear(by), height(h), weight(w) {}

    
    friend std::istream& operator>>(std::istream& is, Person& person) {
        std::string line;
        if (std::getline(is, line)) {
            size_t start = line.find('(');
            size_t end = line.find(')');
            if (start != std::string::npos && end != std::string::npos) {
                std::string content = line.substr(start + 1, end - start - 1);
                std::istringstream iss(content);
                std::string fName, lName;
                char comma;
                if (iss >> person.id >> comma
                    >> std::quoted(fName)
                    >> comma
                    >> std::quoted(lName)
                    >> comma
                    >> person.birthYear
                    >> comma
                    >> person.height
                    >> comma
                    >> person.weight) {
                    person.firstName = fName;
                    person.lastName = lName;
                }
                else {
                    is.setstate(std::ios::failbit);
                }
            }
            else {
                is.setstate(std::ios::failbit);
            }
        }
        else {
            is.setstate(std::ios::failbit);
        }
        return is;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Person("
            << person.id << ", "
            << "\"" << person.firstName << "\", "
            << "\"" << person.lastName << "\", "
            << person.birthYear << ", "
            << std::fixed << std::setprecision(2) << person.height << ", "
            << std::fixed << std::setprecision(2) << person.weight
            << ")";
        return os;
    }
};



inline bool CompareByLastName(const Person& a, const Person& b) {
    return a.lastName < b.lastName;
}

inline bool CompareByFirstName(const Person& a, const Person& b) {
    return a.firstName < b.firstName;
}

inline bool CompareById(const Person& a, const Person& b) {
    return a.id < b.id;
}

inline bool CompareByBirthYear(const Person& a, const Person& b) {
    return a.birthYear < b.birthYear;
}

inline bool CompareByHeight(const Person& a, const Person& b) {
    return a.height < b.height;
}

inline bool CompareByWeight(const Person& a, const Person& b) {
    return a.weight < b.weight;
}