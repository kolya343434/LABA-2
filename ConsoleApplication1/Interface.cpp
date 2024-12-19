#include "Interface.h"
#include "Work_With_Files.h"
#include <limits>
#include <sstream>
#include <fstream>
#include <chrono> 

using namespace std;

// Глобальный указатель на функцию сравнения для Person
static bool (*g_personCmp)(const Person&, const Person&) = CompareByHeight;

// Функция сравнения для Extract<Person>
bool PersonExtractComparator(const Extract<Person>& a, const Extract<Person>& b) {
    return g_personCmp(a.value, b.value);
}

int interfaceForExtract() {
    const int NUM_COUNT = 10000;
    LinkedList<Extract<int>> numbers;

    string filename = "random_numbers.txt";
    ifstream infile(filename);

    if (!infile.is_open()) {
        cerr << "Не удалось открыть файл " << filename << " для чтения.\n";
        return 1;
    }

    int num;
    int index = 0;
    while (index < NUM_COUNT && infile >> num) {
        numbers.Append(Extract<int>(index, num));
        ++index;
    }

    infile.close();

    cout << "Сортировка чисел по значению...\n";

    QuickSort<Extract<int>> sorter;
    sorter.Sort(numbers, compareExtract<int>);

    cout << "Количество чисел: " << numbers.GetLength() << "\n";

    return 0;
}

enum ContainerType {
    LINKED_LIST = 1,
    DYNAMIC_ARRAY = 2
};

enum SortType {
    QUICK_SORT = 1,
    INSERTION_SORT = 2,
    BUBBLE_SORT = 3,
    HEAP_SORT = 4
};

// Функция для выбора типа контейнера
ContainerType chooseContainerType() {
    cout << "Выберите тип контейнера:\n"
        << "1) LinkedList\n"
        << "2) DynamicArray\n"
        << "Ваш выбор: ";
    int choice;
    cin >> choice;

    if (choice == 1) return LINKED_LIST;
    if (choice == 2) return DYNAMIC_ARRAY;

    cout << "Некорректный выбор. Используется LinkedList по умолчанию.\n";
    return LINKED_LIST;
}

// Функция для выбора типа сортировки
SortType chooseSortType() {
    cout << "Выберите тип сортировки:\n"
        << "1) QuickSort\n"
        << "2) InsertionSort\n"
        << "3) BubbleSort\n"
        << "4) HeapSort\n"
        << "Ваш выбор: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: return QUICK_SORT;
    case 2: return INSERTION_SORT;
    case 3: return BUBBLE_SORT;
    case 4: return HEAP_SORT;
    default:
        cout << "Некорректный выбор. Используется QuickSort по умолчанию.\n";
        return QUICK_SORT;
    }
}

// Шаблонная функция для сортировки контейнера
template <typename T, typename Compare>
void sortContainer(Sequence<T>& sequence, SortType sortType, Compare cmp) {
    switch (sortType) {
    case QUICK_SORT: {
        QuickSort<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
    case INSERTION_SORT: {
        InsertionSort<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
    case BUBBLE_SORT: {
        BubbleSorter<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
    case HEAP_SORT: {
        HeapSort<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
    default: {
        QuickSort<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
    }
}

// Шаблонная функция для вывода и записи результатов
template <typename T>
void printAndWriteResult(Sequence<T>& container) {
    cout << "Хотите ли вы вывести последовательность на экран? (Yes/No): ";
    string answer;
    cin >> answer;
    if (answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y") {
        container.Print();
    }
    else if (answer != "No" && answer != "no" && answer != "N" && answer != "n") {
        cout << "Некорректный ввод.\n";
    }

    cout << "Хотите ли вы записать данные в файл? (Yes/No): ";
    cin >> answer;
    if (answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y") {
        string outputFileName;
        cout << "Введите имя выходного файла: ";
        cin >> outputFileName;
        WriteSequenceToFile(outputFileName, &container);
    }
    else if (answer != "No" && answer != "no" && answer != "N" && answer != "n") {
        cout << "Некорректный ввод.\n";
    }
}

// Шаблонная функция для обработки случая с чтением из файла
template <typename T, typename Compare>
void handleFileCase(Compare cmp) {
    while (true) {
        cout << "Введите имя файла: ";
        string fileName;
        cin >> fileName;

        ContainerType containerType = chooseContainerType();
        SortType sortType = chooseSortType();

        bool success;
        if (containerType == LINKED_LIST) {
            LinkedList<T> list;
            success = ReadNumbersFromFile(fileName, list);
            if (!success) {
                cout << "Попробуйте снова.\n";
                continue;
            }

            // Засекаем время до сортировки
            auto start = std::chrono::high_resolution_clock::now();
            sortContainer<T>(list, sortType, cmp);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            cout << "Сортировка заняла: " << duration.count() << " секунд(ы)" << endl;

            printAndWriteResult(list);
        }
        else {
            DynamicArray<T> array;
            success = ReadNumbersFromFile(fileName, array);
            if (!success) {
                cout << "Попробуйте снова.\n";
                continue;
            }

            // Засекаем время до сортировки
            auto start = std::chrono::high_resolution_clock::now();
            sortContainer<T>(array, sortType, cmp);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            cout << "Сортировка заняла: " << duration.count() << " секунд(ы)" << endl;

            printAndWriteResult(array);
        }
        break; // Успешное чтение, выходим из цикла
    }
}

// Шаблонная функция для обработки пользовательского ввода
template <typename T, typename Compare>
void handleUserInputCase(Compare cmp) {
    ContainerType containerType = chooseContainerType();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

    cout << "Введите числа через пробел: ";
    string inputLine;
    getline(cin, inputLine);
    istringstream iss(inputLine);
    T value;

    SortType sortType = chooseSortType();

    if (containerType == LINKED_LIST) {
        LinkedList<T> list;
        while (iss >> value) {
            list.Prepend(value);
        }

        // Засекаем время до сортировки
        auto start = std::chrono::high_resolution_clock::now();
        sortContainer<T>(list, sortType, cmp);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        cout << "Сортировка заняла: " << duration.count() << " секунд(ы)" << endl;

        printAndWriteResult(list);
    }
    else {
        DynamicArray<T> array;
        while (iss >> value) {
            array.Prepend(value);
        }

        // Засекаем время до сортировки
        auto start = std::chrono::high_resolution_clock::now();
        sortContainer<T>(array, sortType, cmp);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        cout << "Сортировка заняла: " << duration.count() << " секунд(ы)" << endl;

        printAndWriteResult(array);
    }
}

// Основная функция интерфейса
void Interface() {
    checking(); // Проверка корректности структур данных и сортировок

    while (true) {
        cout << "\nГлавное меню:\n"
            << "1) Сортировка\n"
            << "2) Сравнение\n"
            << "0) Выход\n"
            << "Ваш выбор: ";

        int mainChoice;
        cin >> mainChoice;

        if (cin.fail()) {
            cout << "Ошибка: пожалуйста, введите корректное число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (mainChoice == 0) {
            cout << "Завершение программы.\n";
            break;
        }

        switch (mainChoice) {
        case 1: { // Сортировка
            cout << "\nПодменю сортировки:\n"
                << "1) Сортировка случайных чисел\n"
                << "2) Чтение чисел из файла\n"
                << "3) Чтение структур из файла\n"
                << "4) Ввод последовательности с консоли\n"
                << "5) Возврат в главное меню\n"
                << "Ваш выбор: ";

            int sortChoice;
            cin >> sortChoice;

            switch (sortChoice) {
            case 1: { // Сортировка случайных чисел
                cout << "Введите количество чисел: ";
                int count;
                cin >> count;
                cout << "Введите имя файла для записи: ";
                string filename;
                cin >> filename;
                WriteRandomNumbersToFile(count, filename);
                handleFileCase<int>(ascendingInt);
                break;
            }
            case 2: { // Чтение чисел из файла
                cout << "\n1) Чтение чисел из файла\n"
                    << "2) Большие данные случайных чисел\n"
                    << "Ваш выбор: ";
                int subChoice;
                cin >> subChoice;

                switch (subChoice) {
                case 1: { // Чтение чисел из файла
                    handleFileCase<int>(ascendingInt);
                    break;
                }
                case 2: { // Большие данные случайных чисел
                    interfaceForExtract();
                    break;
                }
                default:
                    cout << "Некорректный выбор. Попробуйте снова.\n";
                    break;
                }
                break;
            }
            case 3: { // Чтение структур из файла
                // Выбор поля сортировки для Person
                cout << "Выберите поле для сортировки Person:\n"
                    << "1) LastName\n"
                    << "2) FirstName\n"
                    << "3) Id\n"
                    << "4) BirthYear\n"
                    << "5) Height\n"
                    << "6) Weight\n"
                    << "Ваш выбор: ";
                int personFieldChoice;
                cin >> personFieldChoice;

                bool (*personCmp)(const Person&, const Person&) = nullptr;

                switch (personFieldChoice) {
                case 1: personCmp = CompareByLastName; break;
                case 2: personCmp = CompareByFirstName; break;
                case 3: personCmp = CompareById; break;
                case 4: personCmp = CompareByBirthYear; break;
                case 5: personCmp = CompareByHeight; break;
                case 6: personCmp = CompareByWeight; break;
                default:
                    cout << "Некорректный выбор. Используется CompareByHeight.\n";
                    personCmp = CompareByHeight;
                    break;
                }

                {
                    ContainerType containerType = chooseContainerType();
                    SortType sortType = chooseSortType();

                    while (true) {
                        cout << "Введите имя файла со структурами Person: ";
                        string fileName;
                        cin >> fileName;

                        bool success;
                        LinkedList<Person> tempPersons;
                        success = ReadNumbersFromFile<Person>(fileName, tempPersons);
                        if (!success) {
                            cout << "Попробуйте снова.\n";
                            continue;
                        }

                        LinkedList<Extract<Person>> wrapperList;
                        for (int i = 0; i < tempPersons.GetLength(); i++) {
                            wrapperList.Append(Extract<Person>(i, tempPersons.GetElement(i)));
                        }

                        g_personCmp = personCmp;

                        // Засекаем время до сортировки
                        auto start = std::chrono::high_resolution_clock::now();
                        sortContainer<Extract<Person>>(wrapperList, sortType, PersonExtractComparator);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> duration = end - start;

                        cout << "Сортировка заняла: " << duration.count() << " секунд(ы)" << endl;

                        printAndWriteResult(wrapperList);

                        break;
                    }
                }
                break;
            }
            case 4: { // Ввод последовательности с консоли
                handleUserInputCase<int>(ascendingInt);
                break;
            }
            case 5: { // Возврат в главное меню
                cout << "Возврат в главное меню.\n";
                break;
            }
            default:
                cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
            }
            break;
        }
        case 2: { // Сравнение
            comparing();
            break;
        }
        default:
            cout << "Некорректный выбор в главном меню. Попробуйте снова.\n";
            break;
        }
    }
}
