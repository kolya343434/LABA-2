#pragma once

#include "DynamicArray.h"
#include <iostream>


template <class T>
void DynamicArray<T>::Print()  {
    std::cout << "Elements in the array: ";
    for (int i = 0; i < size; i++) { 
        std::cout << data[i] << " "; 
    }
    std::cout << std::endl;
}