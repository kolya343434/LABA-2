#pragma once

/// sequence add to readdata
// ������ ������ �������� � ����� 300 ����

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void WriteRandomNumbersToFile(unsigned long long quantity, const std::string& outputFileName);

template <typename T>
void ReadData(const std::string& fileName, LinkedList<T>& list) {
    std::ifstream inFile(fileName); // ������� ������ ��� ������ �� �����
    if (!inFile) {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return; // ���� ���� �� ��������, ������� �� �������
    }

    T value;
    // ������ ������ �� �����
    while (inFile >> value) {
        list.Append(value); // ��������� ������ ��������� �������� � ������
    }

    inFile.close(); // ��������� ����
}

template <typename T>
void ReadData(const std::string& fileName, DynamicArray<T>& array) {
    std::ifstream inFile(fileName); // ��������� ���� ��� ������
    if (!inFile) {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return; // ���� ���� �� ��������, ������� �� �������
    }

    T value;
    // ������ ������ �� �����
    while (inFile >> value) {
        array.Append(value); // ��������� ������ ��������� �������� � ������
    }

    inFile.close(); // ��������� ����
}

template <typename T>
void ReadNumbersFromFile(const std::string& inputFileName, Sequence<T>& numbers) {
    std::ifstream fileStream(inputFileName); // ������� ������ ��� ������ �� �����

    if (!fileStream.is_open()) { // ���������, �������� �� ����
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return; // ���� ���� �� ��������, ��������� �������
    }

    std::string line;

    // ������ ������ �� �����
    while (std::getline(fileStream, line)) {
        if (line.size() > 300) { // ��������, �� ��������� �� ������ 300 ����
            std::cerr << "Error: Line exceeds 300 bytes: " << line << std::endl;
            continue; // ���������� ������, ����������� 300 ����
        }

        std::istringstream iss(line);
        T item;

        // ������� ��������� ������ � ������ ���
        if (iss >> item) {
            numbers.Append(item); // ��������� ������� � ������������������
        }
        else {
            std::cerr << "Error: Could not convert line to target type: " << line << std::endl;
        }
    }

    fileStream.close(); // ��������� ����
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


