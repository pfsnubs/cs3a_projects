// 10380722, Anthony, Chen
// Date: 12/11/2022
// Homework Project 2

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Book.h"
#include "Person.h"
#include "Node.h"

using namespace std;

// constants
// header strings used for menu prints
const string LINE_HEADER = "-------------------------";
const string EQUAL_HEADER = "====================================================";
const string HALF_EQUAL_HEADER = "=========================";   

const int PERSON_LIST_TOTAL = 2;
const int BOOK_LIST_TOTAL = 3;


// prototype fxns

/*
fxn()
    INPUT:
    OUTPUT:
*/
//int menu1();

// functions
int menu1() {

}

template <class T> void initList(string dir, T* temp, const int listTotal) {
    // creates a Course struct from a file directory
    ifstream infile;
    infile.open(fileName);

    // in each temp pointer entry, have it point to a node of type T (their own class)

    // re-read file again and assign vars 
    while (!infile.eof()) {
        template <typename ... Tn> templatePack;
        cin >> templatePack;
        temp[iter] = new T(templatePack);
        cout << templatePack << endl;
    }
}

int main()
{
    Person* person[PERSON_LIST_TOTAL];
    Book* book[BOOK_LIST_TOTAL];
    initList("programming_hw2\\person.txt", person, PERSON_LIST_TOTAL);
    initList("programming_hw2\\book.txt", book, BOOK_LIST_TOTAL);
    
    // display menu
    // print menu
    cout << LINE_HEADER << endl;
    cout << "\tMenu";
    cout << LINE_HEADER << endl;
    cout << "1. Search a book" << endl;
    cout << "2. Rent a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Show my information" << endl;
    cout << "5. Show all books" << endl;
    cout << "6. Exit" << endl;

    // display input
    int input;
    cout << endl;
    cout << "Select (1`5) : ";
    cin >> input;
    cout << endl;

    // handle menu thru function input
    switch (input) {
    case 1:
        menu1();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
    return 0;
}
