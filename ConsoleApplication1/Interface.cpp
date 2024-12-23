#include "Interface.h"
#include "Work_With_Files.h"


static bool (*g_personCmp)(const Person&, const Person&) = CompareByHeight;


bool PersonExtractComparator(const Extract<Person>& a, const Extract<Person>& b) {
    return g_personCmp(a.value, b.value);
}

int interfaceForExtract() {
    const int NUM_COUNT = 10000;
    LinkedList<Extract<int>> numbers;

    string filename = "random_numbers.txt";
    ifstream infile(filename);

    if (!infile.is_open()) {
        cerr << "Failed to open file " << filename << " for reading.\n";
        return 1;
    }

    int num;
    int index = 0;
    while (index < NUM_COUNT && infile >> num) {
        numbers.Append(Extract<int>(index, num));
        ++index;
    }

    infile.close();

    cout << "Sorting numbers by value...\n";

    QuickSort<Extract<int>> sorter;
    sorter.Sort(numbers, compareExtract<int>);

    cout << "Number of elements: " << numbers.GetLength() << "\n";

    return 0;
}

enum ContainerType {
    LINKED_LIST = 1,
    DYNAMIC_ARRAY = 2
};

enum SortType {
    QUICK_SORT = 1,
    INSERTION_SORT = 2,
    BUBBLE_SORT = 3
    
};


ContainerType chooseContainerType() {
    cout << "Choose container type:\n"
        << "1) LinkedList\n"
        << "2) DynamicArray\n"
        << "Your choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) return LINKED_LIST;
    if (choice == 2) return DYNAMIC_ARRAY;

    cout << "Invalid choice. Using LinkedList by default.\n";
    return LINKED_LIST;
}

SortType chooseSortType() {
    cout << "Choose sorting type:\n"
        << "1) QuickSort\n"
        << "2) InsertionSort\n"
        << "3) BubbleSort\n"
        << "Your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: return QUICK_SORT;
    case 2: return INSERTION_SORT;
    case 3: return BUBBLE_SORT;
    default:
        cout << "Invalid choice. Using QuickSort by default.\n";
        return QUICK_SORT;
    }
}


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
    default: {
        QuickSort<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
    }
}


template <typename T>
void printAndWriteResult(Sequence<T>& container) {
    cout << "Do you want to print the sequence on the screen? (Yes/No): ";
    string answer;
    cin >> answer;
    if (answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y") {
        container.Print();
    }
    else if (answer != "No" && answer != "no" && answer != "N" && answer != "n") {
        cout << "Invalid input.\n";
    }

    cout << "Do you want to write the data to a file? (Yes/No): ";
    cin >> answer;
    if (answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y") {
        string outputFileName;
        cout << "Enter output file name: ";
        cin >> outputFileName;
        WriteSequenceToFile(outputFileName, &container);
    }
    else if (answer != "No" && answer != "no" && answer != "N" && answer != "n") {
        cout << "Invalid input.\n";
    }
}


template <typename T, typename Compare>
void handleFileCase(Compare cmp) {
    while (true) {
        cout << "Enter file name: ";
        string fileName;
        cin >> fileName;

        ContainerType containerType = chooseContainerType();
        SortType sortType = chooseSortType();

        bool success;
        if (containerType == LINKED_LIST) {
            LinkedList<T> list;
            success = ReadNumbersFromFile(fileName, list);
            if (!success) {
                cout << "Try again.\n";
                continue;
            }

            auto start = std::chrono::high_resolution_clock::now();
            sortContainer<T>(list, sortType, cmp);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            cout << "Sorting took: " << duration.count() << " seconds\n";

            printAndWriteResult(list);
        }
        else {
            DynamicArray<T> array;
            success = ReadNumbersFromFile(fileName, array);
            if (!success) {
                cout << "Try again.\n";
                continue;
            }

            auto start = std::chrono::high_resolution_clock::now();
            sortContainer<T>(array, sortType, cmp);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            cout << "Sorting took: " << duration.count() << " seconds\n";

            printAndWriteResult(array);
        }
        break; 
    }
}


template <typename T, typename Compare>
void handleUserInputCase(Compare cmp) {
    ContainerType containerType = chooseContainerType();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Enter numbers separated by spaces: ";
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

        auto start = std::chrono::high_resolution_clock::now();
        sortContainer<T>(list, sortType, cmp);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        cout << "Sorting took: " << duration.count() << " seconds\n";

        printAndWriteResult(list);
    }
    else {
        DynamicArray<T> array;
        while (iss >> value) {
            array.Prepend(value);
        }

        auto start = std::chrono::high_resolution_clock::now();
        sortContainer<T>(array, sortType, cmp);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        cout << "Sorting took: " << duration.count() << " seconds\n";

        printAndWriteResult(array);
    }
}


void Interface() {
    checking(); 

    while (true) {
        cout << "\nMain Menu:\n"
            << "1) Sorting\n"
            << "2) Comparing\n"
            << "0) Exit\n"
            << "Your choice: ";

        int mainChoice;
        cin >> mainChoice;

        if (cin.fail()) {
            cout << "Error: please enter a valid number.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (mainChoice == 0) {
            cout << "Exiting the program.\n";
            break;
        }

        switch (mainChoice) {
        case 1: { // Sorting
            cout << "\nSorting submenu:\n"
                << "1) Sorting random numbers\n"
                << "2) Reading numbers from file\n"
                << "3) Reading structures from file\n"
                << "4) Entering sequence from console\n"
                << "5) Return to main menu\n"
                << "Your choice: ";

            int sortChoice;
            cin >> sortChoice;

            switch (sortChoice) {
            case 1: { 
                cout << "Enter the number of elements: ";
                int count;
                cin >> count;
                cout << "Enter the output file name for random numbers: ";
                string filename;
                cin >> filename;
                WriteRandomNumbersToFile(count, filename);
                handleFileCase<int>(ascendingInt);
                break;
            }
            case 2: { 
                handleFileCase<int>(ascendingInt);
                break;
                
            }
            case 3: { 
                
                cout << "Choose a field to sort Person by:\n"
                    << "1) LastName\n"
                    << "2) FirstName\n"
                    << "3) Id\n"
                    << "4) BirthYear\n"
                    << "5) Height\n"
                    << "6) Weight\n"
                    << "Your choice: ";
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
                    cout << "Invalid choice. Using CompareByHeight by default.\n";
                    personCmp = CompareByHeight;
                    break;
                }

                {
                    ContainerType containerType = chooseContainerType();
                    SortType sortType = chooseSortType();

                    while (true) {
                      
                        string fileName = "people.txt";
                     
                        bool success;
                        LinkedList<Person> tempPersons;
                        success = ReadNumbersFromFile<Person>(fileName, tempPersons);
                        if (!success) {
                            cout << "Try again.\n";
                            continue;
                        }

                        LinkedList<Extract<Person>> wrapperList;
                        for (int i = 0; i < tempPersons.GetLength(); i++) {
                            wrapperList.Append(Extract<Person>(i, tempPersons.GetElement(i)));
                        }

                        g_personCmp = personCmp;

                        auto start = std::chrono::high_resolution_clock::now();
                        sortContainer<Extract<Person>>(wrapperList, sortType, PersonExtractComparator);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> duration = end - start;

                        cout << "Sorting took: " << duration.count() << " seconds\n";

                        printAndWriteResult(wrapperList);

                        break;
                    }
                }
                break;
            }
            case 4: { 
                handleUserInputCase<int>(ascendingInt);
                break;
            }
            case 5: {
                cout << "Returning to main menu.\n";
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
                break;
            }
            break;
        }
        case 2: { 
            //comparing();
            //comparingQuickSort();
           // break;
            int caser;

           
            cout << "Выберите опцию для сравнения сортировок:\n";
            cout << "1) Сравнение всех сортировок\n";
            cout << "2) Сравнение работы быстрой сортировки на разных последовательностях\n";
           
            cin >> caser;

           
            switch (caser) {
            case 1:
                cout << "\nСравнение всех сортировок:\n";
                comparing();
                break;
            case 2:
                cout << "\nСравнение работы быстрой сортировки на разных последовательностях:\n";
                comparingQuickSort();
                break;
            default:
                cout << "\nНеверный выбор. Пожалуйста, введите 1 или 2.\n";
                break;
            }
        }
        default:
           
            break;
        }
    }
}
