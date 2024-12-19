#pragma once
#include <iostream>
#include "DynamicArray.h"

template <class T>
void DynamicArray<T>::Print() {
    std::cout << "Array elements:" << std::endl;
    for (int index = 0; index < size; ++index) {
        std::cout << data[index] << std::endl;
    }
}
