#pragma once
#include <iostream>
#include "LinkedList.h"

template <class T>
void LinkedList<T>::Print() {
    Node* current = head;
    std::cout << "Elements in the list:" << std::endl;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}