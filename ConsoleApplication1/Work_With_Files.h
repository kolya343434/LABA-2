#pragma once

/// sequence add to readdata
// размер одного элемента в файле 300 байт

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void WriteRandomNumbersToFile(unsigned long long quantity, const std::string& outputFileName);

template <typename T>
void ReadData(const std::string& fileName, LinkedList<T>& list) {
    std::ifstream inFile(fileName); // Создаем объект для чтения из файла
    if (!inFile) {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return; // Если файл не открылся, выходим из функции
    }

    T value;
    // Читаем данные из файла
    while (inFile >> value) {
        list.Append(value); // Добавляем каждое считанное значение в список
    }

    inFile.close(); // Закрываем файл
}

template <typename T>
void ReadData(const std::string& fileName, DynamicArray<T>& array) {
    std::ifstream inFile(fileName); // Открываем файл для чтения
    if (!inFile) {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return; // Если файл не открылся, выходим из функции
    }

    T value;
    // Читаем данные из файла
    while (inFile >> value) {
        array.Append(value); // Добавляем каждое считанное значение в массив
    }

    inFile.close(); // Закрываем файл
}

template <typename T>
void ReadNumbersFromFile(const std::string& inputFileName, Sequence<T>& numbers) {
    std::ifstream fileStream(inputFileName); // Создаем объект для чтения из файла

    if (!fileStream.is_open()) { // Проверяем, открылся ли файл
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return; // Если файл не открылся, завершаем функцию
    }

    std::string line;

    // Читаем строки из файла
    while (std::getline(fileStream, line)) {
        if (line.size() > 300) { // Проверка, не превышает ли строка 300 байт
            std::cerr << "Error: Line exceeds 300 bytes: " << line << std::endl;
            continue; // Пропустить строки, превышающие 300 байт
        }

        std::istringstream iss(line);
        T item;

        // Попытка прочитать строку в нужный тип
        if (iss >> item) {
            numbers.Append(item); // Добавляем элемент в последовательность
        }
        else {
            std::cerr << "Error: Could not convert line to target type: " << line << std::endl;
        }
    }

    fileStream.close(); // Закрываем файл
}



template <class T>
void WriteSequenceToFile(std::string& fileName, Sequence<T>* numbers)
{
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    auto begin = numbers->ToBegin();
    auto end = numbers->ToEnd();

    while (*begin != *end)
    {
        outFile << **begin << std::endl;
        ++(*begin);
    }

    std::cout << "The numbers have been successfully written to the file " << fileName << std::endl;

    outFile.close();
}


