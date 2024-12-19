#include "Work_With_Files.h"
#include <random>

// Реализация функции записи случайных чисел в файл
void WriteRandomNumbersToFile(unsigned long long quantity, const std::string& outputFileName) {
    std::ofstream fileStream(outputFileName);
    if (!fileStream.is_open()) {
        std::cerr << "Невозможно открыть файл: " << outputFileName << std::endl;
        return;
    }

    // Используем современный генератор случайных чисел
    std::random_device rd; // Источник энтропии
    std::mt19937 gen(rd()); // Mersenne Twister с сидом от random_device
    std::uniform_int_distribution<> dist(0, 10000); // Равномерное распределение от 0 до 10000

    for (unsigned long long i = 0; i < quantity; ++i) {
        unsigned long long randomValue = dist(gen); // Генерация случайного числа
        fileStream << randomValue << "\n"; // Запись числа в файл
    }

    std::cout << "Сгенерировано " << quantity << " случайных чисел в файл: " << outputFileName << std::endl;
    fileStream.close();
}
