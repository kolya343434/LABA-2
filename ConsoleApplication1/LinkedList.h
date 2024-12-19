#pragma once

#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class LinkedList : public Sequence<T>
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    int length;

public:

    // Внутренний класс итератора для LinkedList
    class LinkedListIterator : public Sequence<T>::Iterator {
    private:
        Node* current;

    public:
        LinkedListIterator(Node* startNode) : current(startNode) { }

        bool operator==(const typename Sequence<T>::Iterator& other) const override
        {
            const LinkedListIterator* otherIt = dynamic_cast<const LinkedListIterator*>(&other);
            return otherIt && (current == otherIt->current);
        }

        bool operator!=(const typename Sequence<T>::Iterator& other) const override
        {
            return !(*this == other);
        }

        T& operator*() override
        {
            return current->data;
        }

        typename Sequence<T>::Iterator& operator++() override
        {
            if (current)
            {
                current = current->next;
            }
            return *this;
        }
    };

    // Методы для получения итераторов
    typename Sequence<T>::Iterator* ToBegin() override
    {
        return new LinkedListIterator(head);
    }

    typename Sequence<T>::Iterator* ToEnd() override
    {
        return new LinkedListIterator(nullptr);
    }

    // Конструкторы
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(T* elements, int count) : head(nullptr), tail(nullptr), length(0)
    {
        for (int i = 0; i < count; ++i)
        {
            Append(elements[i]);
        }
    }

    LinkedList(LinkedList<T>& otherList) : head(nullptr), tail(nullptr), length(0)
    {
        Node* currentNode = otherList.head;

        while (currentNode != nullptr)
        {
            Append(currentNode->data);
            currentNode = currentNode->next;
        }
    }

    LinkedList(DynamicArray<T>& dynamicArr) : head(nullptr), tail(nullptr), length(0)
    {
        for (int i = 1; i < dynamicArr.GetLength(); i++)
        {
            Append(dynamicArr.GetElement(i));
        }
    }

    // Деструктор
    ~LinkedList()
    {
        Node* currentNode = head;
        Node* nextNode;

        while (currentNode != nullptr)
        {
            nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }

    // Перегрузка оператора []
    T& operator[](int index)
    {
        return GetElement(index);
    }

    // Методы доступа к элементам
    T& GetFirstElement() override
    {
        return head->data;
    }

    T& GetLastElement() override
    {
        return tail->data;
    }

    T& GetElement(int index) override
    {
        return GetNode(index)->data;
    }

    // Установка значения элемента по индексу
    void Set(int index, T value) override
    {
        Node* targetNode = GetNode(index);
        targetNode->data = value;
    }

    // Обмен значениями двух элементов
    void Swap(T& a, T& b) override
    {
        T temp = a;
        a = b;
        b = temp;
    }

    // Получение узла по индексу
    Node* GetNode(int index)
    {
        Node* currentNode = head;

        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->next;
        }

        return currentNode;
    }

    // Получение подсписка
    LinkedList<T>* GetSubsequence(int startIdx, int endIdx) override
    {
        if (endIdx >= length)
        {
            endIdx = length - 1;
        }

        LinkedList<T>* subList = new LinkedList<T>();
        Node* currentNode = head;

        for (int i = 0; i <= endIdx; i++)
        {
            if (i >= startIdx)
            {
                subList->Append(currentNode->data);
            }

            currentNode = currentNode->next;
        }

        return subList;
    }

    // Получение длины списка
    int GetLength() override
    {
        return length;
    }

    // Добавление элемента в конец списка
    void Append(T item) override
    {
        Node* newNode = new Node(item);

        if (length == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    // Добавление элемента в начало списка
    void Prepend(T item) override
    {
        Node* newNode = new Node(item, head);

        if (length == 0)
        {
            head = tail = newNode;
        }
        else
        {
            head = newNode;
        }

        length++;
    }

    // Вставка элемента на указанную позицию
    void InsertAt(T item, int index) override
    {
        if (index == 0)
        {
            Prepend(item);
        }
        else if (index == length)
        {
            Append(item);
        }
        else
        {
            Node* prevNode = head;

            for (int i = 0; i < index - 1; ++i)
            {
                prevNode = prevNode->next;
            }

            Node* newNode = new Node(item, prevNode->next);
            prevNode->next = newNode;
            length++;
        }
    }

    // Объединение с другим списком
    void Union(Sequence<T>* otherList) override
    {
        int listLength = otherList->GetLength();

        for (int i = 0; i < listLength; i++)
        {
            Append(otherList->GetElement(i));
        }
    }

 
    void Print() override;


    void Clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        length = 0;
    }

};
