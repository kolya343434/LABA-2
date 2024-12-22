#include "Work_With_Files.h"
#include <random>


void WriteRandomNumbersToFile(unsigned long long quantity, const std::string& outputFileName) {
    std::ofstream fileStream(outputFileName);
    if (!fileStream.is_open()) {
        std::cerr << "Невозможно открыть файл: " << outputFileName << std::endl;
        return;
    }

   
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(0, 10000); 

    for (unsigned long long i = 0; i < quantity; ++i) {
        unsigned long long randomValue = dist(gen); 
        fileStream << randomValue << "\n"; 
    }

    std::cout << "Сгенерировано " << quantity << " случайных чисел в файл: " << outputFileName << std::endl;
    fileStream.close();
}
