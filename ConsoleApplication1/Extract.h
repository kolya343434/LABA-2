#pragma once


template <typename T>
struct Extract {
    int index;    // Поле для хранения индекса 
    T value;      // Поле для хранения значения

    
    Extract() : index(0), value(T()) {}
    Extract(int idx, T val) : index(idx), value(val) {}
    Extract(const Extract& other) : index(other.index), value(other.value) {}
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Extract<T>& obj) {
    os << obj.value;
    return os;
}


template <typename T>
bool compareExtract(const Extract<T>& a, const Extract<T>& b) {
    return a.value < b.value;
}