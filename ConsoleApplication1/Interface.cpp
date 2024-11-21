
#include "Sorting.h"
#include "Work_With_Files.h"
#include "Tests.h"
#include "Interface.h"

using namespace std;


void Interface() {

    QuickSort<int> sorterr;
    LinkedList<int> pot;
   // sorterr.Sort(pot, ascendingInt);
    /*
    cout << loadTestSortSorted(1000, sorterr, ascendingInt) << endl;
    cout << loadTestSort(1000, sorterr, ascendingInt) << endl;
    cout << loadTestSortReverseSorted(1000, sorterr, ascendingInt) << endl;
    cout << "\n";
    cout << loadTestSortSorted(2000, sorterr, ascendingInt) << endl;
    cout << loadTestSort(2000, sorterr, ascendingInt) << endl;
    cout << loadTestSortReverseSorted(2000, sorterr, ascendingInt) << endl;
    cout << "\n";
    cout << loadTestSortSorted(3000, sorterr, ascendingInt) << endl;
    cout << loadTestSort(3000, sorterr, ascendingInt) << endl;
    cout << loadTestSortReverseSorted(3000, sorterr, ascendingInt) << endl;
    */
    int n;
    checking();

    LinkedList<int> tester1;  // Создаем экземпляр связанного списка
    // DynamicArray<int> tester2; // Создаем экземпляр динамического массива

    checking();

    while (true) {
        cout << "1) Sort" << endl;
        cout << "2) Comparing" << endl;
        cout << "0) Exit" << endl;
        cout << "Write number: ";

        // Читаем выбор пользователя
        cin >> n;

        if (cin.fail()) { // Проверяем, если ввод некорректен
            cout << "Error: Please enter a valid number." << endl;
            cin.clear(); // Очищаем состояние cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остаток строки
            continue; // Запрашиваем ввод снова
        }

        if (n == 0) {
            cout << "Program finished." << endl;
            break; // Выход из цикла
        }

        switch (n) {
        case 1: {
            int switcher;
            cout << "1) Random numbers sort\n";
            cout << "2) Read from file numbers\n";
            cout << "3) Read struct from file\n";
            cout << "4) write sequence\n";
            cout << "5) Exit to main menu\n";
            cout << "Write number: ";

            cin >> switcher;

            switch (switcher) {
            case 1: {
                cout << "1) Work with LinkedList" << endl;
                cout << "2) Work with DynamicArray" << endl;

                int switcher_in_case1;
                cin >> switcher_in_case1;

                if (switcher_in_case1 == 1) {
                    int p;
                    string name;

                    cout << "Enter length: ";
                    cin >> p;
                    cout << "File name: ";
                    cin >> name;

                    WriteRandomNumbersToFile(p, name);


                    QuickSort<int> sorter;
                    sorter.Sort(tester1, ascendingInt);
                    ReadNumbersFromFile(name, tester1);
                    cout << "should we print sequence? (Yes/No)" << endl;
                    string write;
                    cin >> write;
                    if (write == "Yes") {
                        tester1.Print();
                    }
                    else if (write == "No") {
                        break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }

                }
                else if (switcher_in_case1 == 2) {
                    int p;
                    string name;

                    cout << "Enter length: ";
                    cin >> p;
                    cout << "File name: ";
                    cin >> name;

                    WriteRandomNumbersToFile(p, name);
                    ReadNumbersFromFile(name, tester1);

                    QuickSort<int> sorter;
                    sorter.Sort(tester1, ascendingInt);

                    cout << "should we print sequence? (Yes/No)" << endl;
                    string write;
                    cin >> write;

                    if (write == "Yes") {
                        tester1.Print();
                    }
                    else if (write == "No") {
                        break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }


                }
                else {
                    cout << "Invalid selection." << endl;
                }
                break; // Добавлено, чтобы выйти из case 1
            }
            case 2: {

                int sele;
                cout << "1)small_data" << endl;
                //  cout << "2)huge_data" << endl;
                cout << "2)from your own file" << endl;
                cin >> sele;

                if (sele == 1) {

                    // Ваш код для чтения и сортировки из файла

                    cout << "1) Work with LinkedList" << endl;
                    cout << "2) Work with DynamicArray" << endl;

                    int switcher_in_case2;
                    cin >> switcher_in_case2;

                    if (switcher_in_case2 == 1) {
                        LinkedList<int> list_int;

                        int choser;

                        cout << "1) Quicksort" << endl;
                        cout << "2) InsertionSort" << endl;
                        cout << "3) BubbleSort" << endl;
                        cout << "Choose sorting: ";
                        cin >> choser;

                        ReadNumbersFromFile("test_small_data.txt", list_int);



                        if (choser == 1) {
                            QuickSort<int> sorterr;
                            sorterr.Sort(list_int, ascendingInt);
                        }
                        else if (choser == 2) {
                            InsertionSort<int> sorterr;
                            sorterr.Sort(list_int, ascendingInt);
                        }
                        else if (choser == 3) {
                            BubbleSorter<int> sorterr;
                            sorterr.Sort(list_int, ascendingInt);

                        }



                        cout << "should we print sequence? (Yes/No)" << endl;
                        string write1;
                        cin >> write1;
                        if (write1 == "Yes") {
                            list_int.Print();
                        }
                        else if (write1 == "No") {
                            //break;
                        }
                        else {
                            cout << "uncorrect data" << endl;
                            break;
                        }


                        // list_int.Print();  Печать отсортированного массива


                        cout << "should we write this data to file ? (Yes/No)" << endl;
                        string write;
                        cin >> write;
                        if (write == "Yes") {

                            string fileNameOut;

                            cout << "write file name" << endl;
                            cin >> fileNameOut;



                            WriteSequenceToFile(fileNameOut, &list_int);

                        }
                        else if (write == "No") {
                            break;
                        }
                        else {
                            cout << "uncorrect data" << endl;
                            break;
                        }


                    }
                    else if (switcher_in_case2 == 2) {
                        DynamicArray<int> list_int;
                        int choser;
                        cout << "1) Quicksort" << endl;
                        cout << "2) InsertionSort" << endl;
                        cout << "3) BubbleSort" << endl;
                        cout << "Choose sorting: ";
                        cin >> choser;

                        ReadNumbersFromFile("test_small_data.txt", list_int);

                        if (choser == 1) {
                            QuickSort<int> sorterr;
                            sorterr.Sort(list_int, ascendingInt);
                        }
                        else if (choser == 2) {
                            InsertionSort<int> sorterr;
                            sorterr.Sort(list_int, ascendingInt);
                        }
                        else if (choser == 3) {
                            BubbleSorter<int> sorterr;
                            sorterr.Sort(list_int, ascendingInt);

                        }


                        cout << "should we print sequence? (Yes/No)" << endl;
                        string write1;
                        cin >> write1;
                        if (write1 == "Yes") {
                            list_int.Print();
                        }
                        else if (write1 == "No") {
                            //break;
                        }
                        else {
                            cout << "uncorrect data" << endl;
                            break;
                        }



                        //list_int.Print(); // Печать отсортированного массива

                        cout << "should we write this data to file ? (Yes/No)" << endl;
                        string write;
                        cin >> write;
                        if (write == "Yes") {

                            string fileNameOut;

                            cout << "write file name" << endl;
                            cin >> fileNameOut;



                            WriteSequenceToFile(fileNameOut, &list_int);

                        }
                        else if (write == "No") {
                            break;
                        }
                        else {
                            cout << "uncorrect data" << endl;
                            break;

                        }
                    }
                    else {
                        cout << "Invalid selection." << endl;
                    }
                    break; // Добавлено, чтобы выйти из case 2
                }

                if (sele == 2) {
                    LinkedList<int > list;
                    cout << "Write file" << endl;
                    string name;
                    cin >> name;
                    ReadNumbersFromFile(name, list);

                    int choser;

                    cout << "1) Quicksort" << endl;
                    cout << "2) InsertionSort" << endl;
                    cout << "3) BubbleSort" << endl;
                    cout << "Choose sorting: ";
                    cin >> choser;

                    if (choser == 1) {
                        QuickSort<int> sorterr;
                        sorterr.Sort(list, ascendingInt);
                    }
                    else if (choser == 2) {
                        InsertionSort<int> sorterr;
                        sorterr.Sort(list, ascendingInt);
                    }
                    else if (choser == 3) {
                        BubbleSorter<int> sorterr;
                        sorterr.Sort(list, ascendingInt);

                    }
                    else {
                        cout << "uncorrect" << endl;
                        break;
                    }
                    cout << "should we print sequence? (Yes/No)" << endl;
                    string write;
                    cin >> write;

                    if (write == "Yes") {
                        list.Print();
                    }
                    else if (write == "No") {
                        // break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }




                    cout << "should we write this data to file ? (Yes/No)" << endl;
                    string writte;
                    cin >> writte;

                    if (writte == "Yes") {

                        string fileNameOut;

                        cout << "write file name" << endl;
                        cin >> fileNameOut;



                        WriteSequenceToFile(fileNameOut, &list);

                    }
                    else if (writte == "No") {
                        break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;

                    }





                }
                break;
            }
            case 3: {


                int selectt;

                cout << "1) Work with LinkedList" << endl;
                cout << "2) Work with DynamicArray" << endl;

                cin >> selectt;

                if (selectt == 1) {

                    LinkedList<Person> personaa;

                    personaa.Clear();
                    ReadNumbersFromFile("people.txt", personaa);
                    // personaa.Print();

                    int choser;

                    cout << "1) Quicksort" << endl;
                    cout << "2) InsertionSort" << endl;
                    cout << "3) BubbleSort" << endl;
                    cin >> choser;

                    cout << "sort_by_height" << endl;
                    if (choser == 1) {
                        QuickSort<Person> sorterr;
                        sorterr.Sort(personaa, CompareByHeight);
                    }
                    else if (choser == 2) {
                        InsertionSort<Person> sorterr;
                        sorterr.Sort(personaa, CompareByHeight);
                    }
                    else if (choser == 3) {
                        BubbleSorter<Person> sorterr;
                        sorterr.Sort(personaa, CompareByHeight);

                    }

                    else {

                        cout << "Invalid selection." << endl;
                    }

                    cout << "should we print sequence? (Yes/No)" << endl;
                    string write1;
                    cin >> write1;
                    if (write1 == "Yes") {
                        personaa.Print();
                    }
                    else if (write1 == "No") {
                        //break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }

                    cout << "should we write this data to file ? (Yes/No)" << endl;
                    string write;
                    cin >> write;
                    if (write == "Yes") {

                        string fileNameOut;

                        cout << "write file name" << endl;
                        cin >> fileNameOut;



                        WriteSequenceToFile(fileNameOut, &personaa);

                    }
                    else if (write == "No") {
                        break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }

                }

                else if (selectt == 2) {
                  
                    DynamicArray<Person> persona;
                    ReadNumbersFromFile("people.txt", persona);
                   
                    cout << "write sequence" << endl;

                    int choser;
                    cout << "1) Quicksort" << endl;
                    cout << "2) InsertionSort" << endl;
                    cout << "3) BubbleSort" << endl;
                    cin >> choser;

                    cout << "sort_by_height" << endl;
                    if (choser == 1) {
                        QuickSort<Person> sorterr;
                        sorterr.Sort(persona, CompareByHeight);
                    }
                    else if (choser == 2) {
                        InsertionSort<Person> sorterr;
                        sorterr.Sort(persona, CompareByHeight);
                    }
                    else if (choser == 3) {
                        BubbleSorter<Person> sorterr;
                        sorterr.Sort(persona, CompareByHeight);

                    }
                    else {
                        cout << "Invalid selection." << endl;
                    }

                    cout << "should we print sequence? (Yes/No)" << endl;
                    string write1;
                    cin >> write1;
                    if (write1 == "Yes") {
                        persona.Print();
                    }
                    else if (write1 == "No") {
                        //break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }

                    cout << "should we write this data to file ? (Yes/No)" << endl;
                    string write;
                    cin >> write;
                    if (write == "Yes") {

                        string fileNameOut;

                        cout << "write file name" << endl;
                        cin >> fileNameOut;



                        WriteSequenceToFile(fileNameOut, &persona);

                    }
                    else if (write == "No") {
                        break;
                    }
                    else {
                        cout << "uncorrect data" << endl;
                        break;
                    }
                    persona.Print();
                    //persona.Clear();
                }






                else {
                    cout << "Invalid selection." << endl;
                }

                break; // Добавлено, чтобы выйти из case 3

            }
            case 4: {
                
                int selectt;
            
                std::cout << "1) Work with LinkedList" << std::endl;
                std::cout << "2) Work with DynamicArray" << std::endl;
                std::cin >> selectt;
               
                // Очищаем символ новой строки из буфера
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               
                if (selectt == 1) {
                    cout << "Введите числа для добавления в контейнер, разделенные пробелами. Нажмите Enter для завершения:";
                    LinkedList<int> lIST;  // Используем long long для больших чисел
                    QuickSort<int> sorterr;
                    
                    std::string input_line;

                   

                    // Считываем строку чисел, ввод завершится после нажатия Enter
                    std::getline(std::cin, input_line);

                    int number = 0;
                    bool has_number = false; // Флаг, указывающий, что мы находимся внутри числа

                    for (char ch : input_line) {
                        if (std::isdigit(ch)) { // Если символ - цифра
                            number = number * 10 + (ch - '0'); // Формируем число
                            has_number = true;
                        }
                        else if (ch == ' ' && has_number) { // Если пробел и есть число
                            lIST.Prepend(number); // Добавляем число в список
                            number = 0;           // Сбрасываем для следующего числа
                            has_number = false;   // Устанавливаем флаг
                        }
                    }

                    // Добавляем последнее число, если оно было введено
                    if (has_number) {
                        lIST.Prepend(number);
                    }

                    // Выводим список
                    cout << "Числа, добавленные в LinkedList:" << endl;
                    lIST.Print();

                    int choser;
                    cout << "1) Quicksort" << endl;
                    cout << "2) InsertionSort" << endl;
                    cout << "3) BubbleSort" << endl;
                    cin >> choser;


                    if (choser == 1) {
                        QuickSort<int> sorterrr;
                        sorterrr.Sort(lIST, ascendingInt);
                    }
                    else if (choser == 2) {
                        InsertionSort<int> sorterrr;
                        sorterrr.Sort(lIST, ascendingInt);
                    }
                    else if (choser == 3) {
                        BubbleSorter<int> sorterrr;
                        sorterrr.Sort(lIST, ascendingInt);

                    }
                    else {
                        cout << "Invalid selection." << endl;
                        break;
                    }

                    // Сортируем и выводим отсортированный список

                    lIST.Print();

                }

                else if (selectt == 2) {


                    DynamicArray<int> lISTt;  // Используем long long для больших чисел
                    //Sort<long long> sorterr;

                    std::string input_line;

                    std::cout << "Введите числа для добавления в DynamicArray, разделенные пробелами. Нажмите Enter для завершения:" << std::endl;

                    // Считываем строку чисел, ввод завершится после нажатия Enter
                    std::getline(std::cin, input_line);

                    int number = 0;
                    bool has_number = false; // Флаг, указывающий, что мы находимся внутри числа

                    for (char ch : input_line) {

                        if (std::isdigit(ch)) { // Если символ - цифра
                            number = number * 10 + (ch - '0'); // Формируем число
                            has_number = true;
                        }

                        else if (ch == ' ' && has_number) { // Если пробел и есть число
                            lISTt.Prepend(number); // Добавляем число в список
                            number = 0;           // Сбрасываем для следующего числа
                            has_number = false;   // Устанавливаем флаг
                        }
                    }

                    // Добавляем последнее число, если оно было введено
                    if (has_number) {
                        lISTt.Prepend(number);
                    }

                    // Выводим список
                    std::cout << "Числа, добавленные в LinkedList:" << std::endl;
                    lISTt.Print();

                    int choser;
                    cout << "1) Quicksort" << endl;
                    cout << "2) InsertionSort" << endl;
                    cout << "3) BubbleSort" << endl;
                    cin >> choser;

                    if (choser == 1) {
                        QuickSort<int> sorterrr;
                        sorterrr.Sort(lISTt, ascendingInt);
                    }
                    else if (choser == 2) {
                        InsertionSort<int> sorterrr;
                        sorterrr.Sort(lISTt, ascendingInt);
                    }
                    else if (choser == 3) {
                        BubbleSorter<int> sorterrr;
                        sorterrr.Sort(lISTt, ascendingInt);

                    }
                    else {
                        cout << "Invalid selection." << endl;
                        break;
                    }

                    // Сортируем и выводим отсортированный список

                    lISTt.Print();


                }
                else {
                    cout << "Invalid selection." << endl;
                }
                break;
            }
            case 5: {

                cout << "Returning to the main menu." << endl;
                break;

            }
            default:
                cout << "Incorrect selection, please try again." << endl;
            }
            break; // Добавлено, чтобы выйти из case 1 в основном switch
        }
        case 2: {
            comparing();
            break;
        }
        default:
            cout << "Incorrect selection in the main menu, please try again." << endl;
        }

    }
}