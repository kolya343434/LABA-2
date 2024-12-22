#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "LinkedList.h"

void WriteRandomNumbersToFile(unsigned long long quantity, const std::string& outputFileName);


template <typename T>
bool ReadNumbersFromFile(const std::string& inputFileName, Sequence<T>& numbers) {
    std::ifstream fileStream(inputFileName);
    if (!fileStream.is_open()) {
        std::cerr << "Ошибка открытия файла: " << inputFileName << std::endl;
        return false;
    }

    std::string line;
    bool success = false;

    while (std::getline(fileStream, line)) {
        std::istringstream iss(line);
        T item;
        if (iss >> item) {
            numbers.Append(item);
            success = true;
        }
        else {
            std::cerr << "Ошибка конвертации строки: " << line << std::endl;
        }
    }

    fileStream.close();
    return success;
}

template <typename T>
void WriteSequenceToFile(const std::string& fileName, Sequence<T>* numbers) {
    if (!numbers) {
        std::cerr << "Ошибка: указатель на последовательность равен nullptr." << std::endl;
        return;
    }

    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла: " << fileName << std::endl;
        return;
    }

    auto beginIt = numbers->ToBegin();
    auto endIt = numbers->ToEnd();

    while (*beginIt != *endIt) {
        outFile << **beginIt << std::endl;
        ++(*beginIt);
    }

    std::cout << "Числа успешно записаны в файл " << fileName << std::endl;
    outFile.close();
}
