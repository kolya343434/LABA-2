#pragma once

#include "Sequence.h"

using namespace std;

template <class T>
class DynamicArray : public Sequence<T>
{
private:
    T* data;
    int size;

    // Метод для изменения размера массива
    void Resize(int newSize)
    {
        T* newData = new T[newSize];
        int minSize = (newSize < size) ? newSize : size;

        for (int i = 0; i < minSize; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }

public:
    // Внутренний класс итератора
    class DynamicArrayIterator : public Sequence<T>::Iterator {
    private:
        T* current;

    public:
        DynamicArrayIterator(T* ptr) : current(ptr) { }

        bool operator==(const typename Sequence<T>::Iterator& other) const override
        {
            const DynamicArrayIterator* otherIt = dynamic_cast<const DynamicArrayIterator*>(&other);
            return otherIt && (current == otherIt->current);
        }

        bool operator!=(const typename Sequence<T>::Iterator& other) const override
        {
            return !(*this == other);
        }

        T& operator*() override
        {
            return *current;
        }

        typename Sequence<T>::Iterator& operator++() override
        {
            ++current;
            return *this;
        }
    };

    // Методы итераторов
    typename Sequence<T>::Iterator* ToBegin() override
    {
        return new DynamicArrayIterator(data);
    }

    typename Sequence<T>::Iterator* ToEnd() override
    {
        return new DynamicArrayIterator(data + size);
    }

    // Конструкторы
    DynamicArray() : size(0), data(nullptr) {}

    DynamicArray(T* items, int sz)
    {
        size = sz;
        data = new T[size];
        for (int i = 0; i < size; ++i)
        {
            Set(i, items[i]);
        }
    }

    DynamicArray(int sz)
    {
        size = sz;
        data = new T[size];
    }

    DynamicArray(DynamicArray<T>& other)
    {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
        {
            Set(i, other.data[i]);
        }
    }

    // Деструктор
    ~DynamicArray()
    {
        delete[] data;
    }

    // Перегрузка оператора []
    T& operator[](int index)
    {
        return data[index];
    }

    // Методы доступа
    T& GetFirstElement() override
    {
        return GetElement(0);
    }

    T& GetLastElement() override
    {
        return GetElement(size - 1);
    }

    T& GetElement(int index) override
    {
        return data[index];
    }

    void Set(int index, T value) override
    {
        data[index] = value;
    }

    // Метод обмена двух элементов
    void Swap(T& a, T& b) override
    {
        T temp = a;
        a = b;
        b = temp;
    }

    // Получение подмассивов
    DynamicArray<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        int length;

        if (endIndex > size)
        {
            length = size - startIndex;
        }
        else
        {
            length = endIndex - startIndex + 1;

            if (startIndex == 0)
            {
                length -= 1;
            }
        }

        T* items = new T[length];
        for (int i = 0; i < length; ++i)
        {
            items[i] = GetElement(startIndex + i);
        }

        return new DynamicArray<T>(items, length);
    }

    // Получение длины массива
    int GetLength() override
    {
        return size;
    }

    // Методы добавления элементов
    void Append(T value) override
    {
        InsertAt(value, size);
    }

    void Prepend(T value) override
    {
        InsertAt(value, 0);
    }

    void InsertAt(T value, int index) override
    {
        Resize(size + 1);

        for (int i = size - 1; i > index; --i)
        {
            Set(i, GetElement(i - 1));
        }

        Set(index, value);
    }

    // Объединение с другой последовательностью
    void Union(Sequence<T>* otherSeq) override
    {
        for (int i = 0; i < otherSeq->GetLength(); i++)
        {
            Append(otherSeq->GetElement(i));
        }
    }

    void Print() override;

    // Метод очистки массива
    void Clear() {
        delete[] data;
        data = nullptr;
        size = 0;
    }
};