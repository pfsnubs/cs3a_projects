// 10380722, Anthony, Chen
// Date: 12/11/2022
// Homework Project 2

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "BookFiles\\Book.h"
#include "BookFiles\\BookNode.h"
#include "PersonFiles\\Person.h"
#include "PersonFiles\\PersonNode.h"

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
    return 0;
}

void initPersonList(string dir, PersonNodePtr*& person, const int listTotal) {
    // creates a Course struct from a file directory
    ifstream infile;
    infile.open(dir);

    // find heads of list
    // TODO: FIX NODE STUFF SO THAT WE CAN EDIT ENTRIES IN PERSON WITH ->
    PersonNodePtr teacherList = person[0];
    PersonNodePtr studentList = person[1];

    // re-read file again and assign vars 
    int iter = 0;
    while (!infile.eof()) {
        cout << "BRUH" << endl;

        // take in ID to determine class to create
        int newId;
        infile >> newId;

        // set up new node
        PersonNode* node = new PersonNode();
        int newCount;
        int* code = new int;
        string newName;
        infile >> newName >> newCount >> *code;

        // construct Teacher from ID 1-100
        if (newId >= 1 && newId <= 100) {
            Teacher newPerson(newId, newName, newCount, code);
            node->data = newPerson;

            // create node from head
            PersonNodePtr prevNode = teacherList->link;
            studentList->link = node;
            node->link = prevNode;
        }
        // construct Student from ID 101-300
        else if (newId >= 101 && newId <= 300) {
            Student newPerson(newId, newName, newCount, code);
            node->data = newPerson;

            // create node from head
            PersonNodePtr prevNode = studentList->link;
            studentList->link = node;
            node->link = prevNode;
        }
        
        iter++;
    }
    cout << &teacherList;
}

int main()
{
    PersonNodePtr* person[PERSON_LIST_TOTAL];
    BookNodePtr book[BOOK_LIST_TOTAL];
    initPersonList("programming_hw2\\person.txt", person, PERSON_LIST_TOTAL);
    //initBookList("programming_hw2\\book.txt", book, BOOK_LIST_TOTAL);
    
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
