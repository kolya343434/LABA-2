#pragma once

#include <iostream>

#include "LinkedList.h"

template <class T>
void LinkedList<T>::Print() {
    Node* current = head;
    cout << "Elements in the list: ";
    while (current) {
        cout << current->data<< " "; 
        current = current->next;
    }
    cout << endl;
}