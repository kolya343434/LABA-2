#include "Interface.h"

using namespace std;

int interface_for_extract() {

    const int NUM_COUNT = 10000; 
    LinkedList<Extract<int>> numbers; 

    std::string filename = "random_numbers.txt"; 
    std::ifstream infile(filename);

    if (!infile.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << " для чтения.\n";
        return 1;
    }

    int num;
    int i = 0;
    while (i < NUM_COUNT && infile >> num) {
        numbers.Append(Extract<int>(i, num)); 
        ++i;
    }

    infile.close(); 

    std::cout << "Сортировка чисел по значению...\n";

    QuickSort<Extract<int>> sorter;

    sorter.Sort(numbers, compareExtract<int>);

    std::cout << "Отсортированные числа:\n";

   // numbers.Print();

    std::cout << "Количество чисел: " << numbers.GetLength() << "\n";

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
    cout << "1) Work with LinkedList\n"
        << "2) Work with DynamicArray\n";
    int choice;
    cin >> choice;
    if (choice == 1) return LINKED_LIST;
    else if (choice == 2) return DYNAMIC_ARRAY;
    else {
        cout << "Invalid selection. Using default LinkedList.\n";
        return LINKED_LIST;
    }
}

//  выбор сортировки
SortType chooseSortType() {
    cout << "1) Quicksort\n"
        << "2) InsertionSort\n"
        << "3) BubbleSort\n"
        << "Choose sorting: ";
    int ch;
    cin >> ch;
    switch (ch) {
    case 1: return QUICK_SORT;
    case 2: return INSERTION_SORT;
    case 3: return BUBBLE_SORT;
    default:
        cout << "Invalid selection. Using QuickSort by default.\n";
        return QUICK_SORT;
    }
}



//  для сортировки 
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
    default:
        QuickSort<T> sorter;
        sorter.Sort(sequence, cmp);
        break;
    }
}


template <typename T>
void printAndWriteResult(Sequence<T>& container) {
    cout << "Should we print sequence? (Yes/No)\n";
    {
        string answer;
        cin >> answer;
        if (answer == "Yes") {
            container.Print();
        }
        else if (answer != "No") {
            cout << "Uncorrect data" << endl;
        }
    }

    cout << "Should we write this data to file? (Yes/No)\n";
    {
        string answer;
        cin >> answer;
        if (answer == "Yes") {
            string fileNameOut;
            cout << "Write file name: ";
            cin >> fileNameOut;
            WriteSequenceToFile(fileNameOut, &container);
        }
        else if (answer != "No") {
            cout << "Uncorrect data" << endl;
        }
    }
}

// чтения из файла и сортировки
template <typename T, typename Compare>
void handleFileCase(const string& fileName, Compare cmp) {
    ContainerType ct = chooseContainerType();
    SortType st = chooseSortType();

    if (ct == LINKED_LIST) {
        LinkedList<T> list;
        ReadNumbersFromFile(fileName, list);
        sortContainer<T>(list, st, cmp);
        printAndWriteResult(list);
    }
    else {
        DynamicArray<T> arr;
        ReadNumbersFromFile(fileName, arr);
        sortContainer<T>(arr, st, cmp);
        printAndWriteResult(arr);
    }
}

//  обработки ввода от пользователя
template <typename T, typename Compare>
void handleUserInputCase(Compare cmp) {
    ContainerType ct = chooseContainerType();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера
    cout << "Write numbers to add: ";
    string input_line;
    std::getline(std::cin, input_line);

    SortType st = chooseSortType();

    if (ct == LINKED_LIST) {
        LinkedList<T> list;
        {
            std::istringstream iss(input_line);
            T val;
            while (iss >> val) {
                list.Prepend(val);
            }
        }
        sortContainer<T>(list, st, cmp);
        list.Print();
    }
    else {
        DynamicArray<T> arr;
        {
            std::istringstream iss(input_line);
            T val;
            while (iss >> val) {
                arr.Prepend(val);
            }
        }
        sortContainer<T>(arr, st, cmp);
        arr.Print();
    }
}




void Interface() {
    checking(); 

    while (true) {
        cout << "1) Sort" << endl;
        cout << "2) Comparing" << endl;
        cout << "0) Exit" << endl;
        cout << "Write number: ";

        int n;
        cin >> n;

        if (cin.fail()) {
            cout << "Error: Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (n == 0) {
            cout << "Program finished." << endl;
            break;
        }

        switch (n) {
        case 1: {
            cout << "1) Random numbers sort\n"
                << "2) Read from file numbers\n"
                << "3) Read struct from file\n"
                << "4) Write sequence from console\n"
                << "5) Exit to main menu\n";
            int switcher;
            cin >> switcher;

            switch (switcher) {
            case 1: {
                
                cout << "Enter length: ";
                int p; cin >> p;
                cout << "File name: ";
                string name; cin >> name;
                WriteRandomNumbersToFile(p, name);
                handleFileCase<int>(name, ascendingInt);
                break;
            }
            case 2: {
                
                cout 
                    << "1) Read from file numbers\n"
                    << "2) Random numbers sort\n";

                int n;
                cin >> n;

                switch (n) {
                case 1: {
                    cout << "Write file: ";
                    string fname; cin >> fname;
                    handleFileCase<int>(fname, ascendingInt);
                }
                case 2: {
                    interface_for_extract();
                }
                default:
                    cout << "Incorrect selection, please try again." << endl;
                    break;
                }
                break;

            }
                

            
            case 3: {
        
                cout << "Sort by height" << endl;
                handleFileCase<Person>("people.txt", CompareByHeight);
                break;
            }
            case 4: {
               
                handleUserInputCase<int>(ascendingInt);
                break;
            }
            case 5: {
                cout << "Returning to the main menu." << endl;
                break;
            }
            default:
                cout << "Incorrect selection, please try again." << endl;
                break;
            }
            break;
        }
        case 2: {
            comparing();
            break;
        }
        default:
            cout << "Incorrect selection in the main menu, please try again." << endl;
            break;
        }
    }
}
