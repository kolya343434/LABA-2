#pragma once

#include "Sequence.h"

//график обычный до 5000 эллементов

//название плохое ,помен€ть 
// должен быть один метод название отсортировать и у него должно быть н наследников по числу реализуемых алгоритмов
// избавитьс€ от копипаста в интерфейс
//об€зан включить sequence/ h компил€ци€ не может зависить от пор€дка включени€ файлов
//если передать nullptr in isorted = segmentation fault защита 
// по умолчанию передаетс€ константна€ ссылка в 
//надо передавать ссылка, может сломатьс€ адрес - 

template <class T>
class ISorter {
public:
    virtual void Sort(Sequence<T>& sequence, bool (*precedes)(const T& first, const T& second)) = 0;

    virtual ~ISorter() {}
};


