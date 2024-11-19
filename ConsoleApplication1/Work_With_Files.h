#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void WriteRandomNumbersToFile(unsigned long long quantity, const std::string& outputFileName);



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



/// sequence add to readdata
// ������ ������ �������� � ����� 300 ����