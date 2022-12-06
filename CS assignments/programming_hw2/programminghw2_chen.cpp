// 10380722, Anthony, Chen
// Date: 12/11/2022
// Homework Project 2

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

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
PersonNodePtr personByID(PersonNodePtr* person, int id) {
    PersonNodePtr& teacherList = person[0];
    PersonNodePtr& studentList = person[1];

    // determine node list to search through first
    PersonNodePtr selectedNodeList = NULL;
    // teachers from ID 1-100
    if (id >= 1 && id <= 100) {
        selectedNodeList = teacherList;
    }
    // students from ID 101-300
    else if (id >= 101 && id <= 300) {
        selectedNodeList = studentList;
    }

    PersonNodePtr selectedNode = NULL;
    // try to find node in whichever list
    for (PersonNodePtr temp = selectedNodeList; temp != NULL; temp = temp->link) {
        if (temp->data->getId() == id) {
            selectedNode = temp;
        }
    }

    if (selectedNode == NULL) {
        // TODO: error here
    }

    return selectedNode;
}

PersonNodePtr personByName(PersonNodePtr* person, string name) {
    PersonNodePtr& teacherList = person[0];
    PersonNodePtr& studentList = person[1];
    PersonNodePtr selectedNode = NULL;
    
    // try to find in teacher list
    for (PersonNodePtr temp = teacherList; temp != NULL; temp = temp->link) {
        if (temp->data->getName() == name) {
            selectedNode = temp;
        }
    }

    // try to find in students list
    for (PersonNodePtr temp = studentList; temp != NULL; temp = temp->link) {
        if (temp->data->getName() == name) {
            selectedNode = temp;
        }
    }

    if (selectedNode == NULL) {
        // TODO: error here
    }

    return selectedNode;
}

BookNodePtr bookByCode(BookNodePtr* books, int code) {
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];
    BookNodePtr selectedBookList = NULL;

    // children's books from ID 1001-2000
    if (code >= 1001 && code <= 2000) {
        selectedBookList = childBookList;
    }
    // CS books from ID 2001-3000
    else if (code >= 2001 && code <= 3000) {
        selectedBookList = compBooklist;
    }
    // novel books from ID 3001-4000
    else if (code >= 3001 && code <= 4000) {
        selectedBookList = novelList;
    }

    BookNodePtr selectedNode = NULL;
    // try to find node in whichever list
    for (BookNodePtr temp = selectedBookList; temp != NULL; temp = temp->link) {
        if (temp->data->getCodeID() == code) {
            selectedNode = temp;
        }
    }

    if (selectedNode == NULL) {
        // TODO: error here
    }

    return selectedNode;
}

BookNodePtr bookByTitle(BookNodePtr* books, string title) {
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];
    BookNodePtr selectedNode = NULL;

    // try to find in children's book list
    for (BookNodePtr temp = childBookList; temp != NULL; temp = temp->link) {
        if (temp->data->getBookName() == title) {
            selectedNode = temp;
        }
    }

    // try to find in computer book list
    for (BookNodePtr temp = compBooklist; temp != NULL; temp = temp->link) {
        if (temp->data->getBookName() == title) {
            selectedNode = temp;
        }
    }

    // try to find in novel list
    for (BookNodePtr temp = novelList; temp != NULL; temp = temp->link) {
        if (temp->data->getBookName() == title) {
            selectedNode = temp;
        }
    }

    if (selectedNode == NULL) {
        // TODO: error here
    }

    return selectedNode;
}


void initPersonList(string dir, PersonNodePtr* person, const int listTotal) {    
    // find heads of list
    PersonNodePtr& teacherList = person[0];
    PersonNodePtr& studentList = person[1];  
    teacherList = NULL;
    studentList = NULL;

    // re-read file again and assign vars 
    int iter = 0;
    ifstream infile;
    infile.open(dir);
    while (!infile.eof()) {
        string line;
        getline(infile, line);

        // set up new node
        PersonNodePtr node = new PersonNode();
        int newId;
        int newCount;
        string newName;

        // stringstream class check
        stringstream ss;
        ss << line;

        // filter first few class vars
        ss >> newId >> newName >> newCount;

        // construct Teacher from ID 1-100
        if (newId >= 1 && newId <= 100){
            // create code with entries of books rented off the latter string
            int* code = new int[TEACHER_CODES]{0};
            string codeStr;
            int i = 0;
            while (getline(ss, codeStr, ' '))
            {
                if (codeStr.length() > 0) {
                    code[i] = stoi(codeStr);
                    i++;
                }
            }

            Teacher* newPerson = new Teacher(newId, newName, newCount, code);
            node->data = newPerson;

            // create node from head
            if (teacherList == NULL) {
                teacherList = node;
            }
            else if (teacherList->data->getId() < node->data->getId()) {
                PersonNodePtr prev = NULL;

                // traverse list from back
                for (PersonNodePtr temp = teacherList; temp != NULL; temp = temp->link) {
                    if (temp->data->getId() < node->data->getId()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != NULL) {
                            prev->link = temp;
                        }
                        prev = temp;
                    }
                }
            }
            else {
                node->link = teacherList;
                teacherList = node;
            }
        }
        // construct Student from ID 101-300
        else if (newId >= 101 && newId <= 300) {
            // create code with entries of books rented off the latter string
            int* code = new int[STUDENT_CODES]{0};
            string codeStr;
            int i = 0;
            while (getline(ss, codeStr, ' '))
            {
                if (codeStr.length() > 0) {
                    code[i] = stoi(codeStr);
                    i++;
                }
            }
            Student* newPerson = new Student(newId, newName, newCount, code);
            node->data = newPerson;

            // create node from head
            if (studentList == NULL) {
                studentList = node;
            }
            else if (studentList->data->getId() < node->data->getId()) {
                PersonNodePtr prev = NULL;

                // traverse list from back
                for (PersonNodePtr temp = studentList; temp != NULL; temp = temp->link) {
                    if (temp->data->getId() < node->data->getId()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != NULL) {
                            prev->link = temp;
                        }
                        prev = temp;
                    }
                }
            }
            else {
                node->link = studentList;
                studentList = node;
            }
        }
        
        iter++;
    }
}

void initBookList(string dir, BookNodePtr* books, const int listTotal) {
    // find heads of list
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];
    childBookList = NULL;
    compBooklist = NULL;
    novelList = NULL;

    // re-read file again and assign vars 
    int iter = 0;
    ifstream infile;
    infile.open(dir);
    while (!infile.eof()) {
        string line;

        // set up new node
        BookNodePtr node = new BookNode();
        int code;
        string title;

        // add available and rented AFTER book has been determined
        // since assignment varies a 3rd custom variable after string title
        int available;
        int rented;
        string newName;
        infile >> code >> title;

        // construct child books from ID 1001-2000
        if (code >= 1001 && code <= 2000) {
            // 3rd variable called age
            int age;
            infile >> age >> available >> rented;
            getline(infile, line);

            // create class
            ChildrenBook* newPerson = new ChildrenBook(code, title, age, available, rented);
            node->data = newPerson;

            // create node from head
            if (childBookList == NULL) {
                childBookList = node;
            }
            else if (childBookList->data->getCodeID() < node->data->getCodeID()) {
                BookNodePtr prev = NULL;

                // traverse list from back
                for (BookNodePtr temp = childBookList; temp != NULL; temp = temp->link) {
                    if (temp->data->getCodeID() < node->data->getCodeID()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != NULL) {
                            prev->link = temp;
                        }
                        prev = temp;
                    }
                }
            }
            else {
                node->link = childBookList;
                childBookList = node;
            }
        }
        // construct CS books from ID 2001-3000
        else if (code >= 2001 && code <= 3000) {
            // 3rd variable called publisher
            string publisher;
            infile >> publisher >> available >> rented;
            getline(infile, line);

            // create class
            ComputerBook* newPerson = new ComputerBook(code, title, publisher, available, rented);
            node->data = newPerson;

            // create node from head
            if (compBooklist == NULL) {
                compBooklist = node;
            }
            else if (compBooklist->data->getCodeID() < node->data->getCodeID()) {
                BookNodePtr prev = NULL;

                // traverse list from back
                for (BookNodePtr temp = compBooklist; temp != NULL; temp = temp->link) {
                    if (temp->data->getCodeID() < node->data->getCodeID()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != NULL) {
                            prev->link = temp;
                        }
                        prev = temp;
                    }
                }
            }
            else {
                node->link = compBooklist;
                compBooklist = node;
            }
        }
        // construct novel books from ID 3001-4000
        else if (code >= 3001 && code <= 4000) {
            // 3rd variable called publisher
            int publish_date;
            infile >> publish_date >> available >> rented;
            getline(infile, line);

            // create class
            Novel* newPerson = new Novel(code, title, publish_date, available, rented);
            node->data = newPerson;

            // create node from head
            if (novelList == NULL) {
                novelList = node;
            }
            else if (novelList->data->getCodeID() < node->data->getCodeID()) {
                BookNodePtr prev = NULL;

                // traverse list from back
                for (BookNodePtr temp = novelList; temp != NULL; temp = temp->link) {
                    if (temp->data->getCodeID() < node->data->getCodeID()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != NULL) {
                            prev->link = temp;
                        }
                        prev = temp;
                    }
                }
            }
            else {
                node->link = novelList;
                novelList = node;
            }
        }

        iter++;
    }
}

void menu1(BookNodePtr* books, const int listTotal) {
    int codeSearch;
    cout << "Enter code : ";
    cin >> codeSearch;

    string titleSearch;
    cout << "Enter title : ";
    cin >> titleSearch;

    // try to find and access book
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];
    BookNodePtr selectedList = childBookList;

    // children's books from 1001-2000
    bool foundBook = false;
    string bookType;
    if (codeSearch >= 1001 && codeSearch <= 2000) {
        bookType = "children's";
        selectedList = childBookList;
    }
    // CS books from ID 2001-3000
    else if (codeSearch >= 2001 && codeSearch <= 3000) {
        bookType = "computer";
        selectedList = compBooklist;
    }
    // novel books from ID 3001-4000
    else if (codeSearch >= 3001 && codeSearch <= 4000) {
        bookType = "novel";
        selectedList = novelList;
    }

    // look through entry to find book
    Book* bookPtr = NULL;
    for (BookNodePtr temp = selectedList; temp != NULL; temp = temp->link) {
        if (temp->data->getCodeID() == codeSearch
            && temp->data->getBookName() == titleSearch) {
            bookPtr = temp->data;
            foundBook = true;
        }
    }

    if (foundBook) {
        cout << bookPtr->getBookName() << "(" << bookPtr->getCodeID() << ") exists." << endl;
        cout << "category : " << bookType << endl;

        // print special quantity from each book type
        if (bookType == "children's") {
            cout << "age : " << bookPtr->getAge() << endl;
        }
        else if (bookType == "computer") {
            cout << "publisher : " << bookPtr->getPublisher() << endl;
        }
        else if (bookType == "novel") {
            cout << "publish date : " << bookPtr->getPublishDate() << endl;
        }
        cout << bookPtr->getAvailable() << " available, " << bookPtr->getRented() << " rented" << endl;
    }
}

void menu2(PersonNodePtr* person, const int personTotal, BookNodePtr* books, const int bookTotal) {
    int userId;
    cout << "Enter id : ";
    cin >> userId;

    string titleSearch;
    cout << "Enter book title : ";
    cin >> titleSearch;

    // try to find and access book
    PersonNodePtr selectedPerson = personByID(person, userId);
    BookNodePtr selectedBook = bookByTitle(books, titleSearch);

    int personCount = selectedPerson->data->getCount();
    string personName = selectedPerson->data->getName();
    if (personCount == 1) {
        cout << "You are " << personName
            << ". You rented " << personCount << " book."
            << endl;
    }
    else {
        cout << "You are " << personName
            << ". You rented " << personCount << " books."
            << endl;
    }
    
    char choice;
    cout << "Do you want to rent '" << selectedBook->data->getBookName() << "' (y/n)? ";
    cin >> choice;
    
    if (choice == 'y') {
        // TODO: add error for over-rented

        int personID = selectedPerson->data->getId();
        int bookID = selectedBook->data->getCodeID();
        
        int maxRentals;
        // teachers from ID 1-100
        if (personID >= 1 && personID <= 100) {
            maxRentals = TEACHER_CODES;
        }
        // students from ID 101-300
        else if (personID >= 101 && personID <= 300) {
            maxRentals = STUDENT_CODES;
        }

        // make sure book has an available rental
        // and that the person doesn't max out codes or has book already
        int bookAvailables = selectedBook->data->getAvailable();
        if (bookAvailables > 0
            && personCount != maxRentals 
            && !selectedPerson->data->checkCodeExists(selectedPerson->data, bookID, maxRentals) 
            ) {
            // start transaction for rental
            cout << selectedPerson << endl;
            selectedPerson->data->rentBook(selectedPerson->data, bookID, maxRentals);
            selectedBook->data->attemptToRent();
            
            cout << "***** Rent succeeded. Check your info!" << endl;
            cout << selectedPerson << endl;
        }
        else {
            // TODO: put handler for too much books and the like
        }
        
    }
    else if (choice == 'n') {

    }
    else {
        // TODO: add error for choice input
    }

    
    


}

void menu3(PersonNodePtr* person, const int personTotal, BookNodePtr* books, const int bookTotal) {
    int userId;
    cout << "Enter id : ";
    cin >> userId;

    int bookCode;
    cout << "Enter book code to return : ";
    cin >> bookCode;

    // try to find and access book
    PersonNodePtr selectedPerson = personByID(person, userId);
    BookNodePtr selectedBook = bookByCode(books, bookCode);

    char choice;
    cout << "Do you want to return '" << selectedBook->data->getBookName() << "' (y/n)? ";
    cin >> choice;

    if (choice == 'y') {
        // TODO: add error for over-rented

        int personID = selectedPerson->data->getId();
        int bookID = selectedBook->data->getCodeID();

        int maxRentals;
        // teachers from ID 1-100
        if (personID >= 1 && personID <= 100) {
            maxRentals = TEACHER_CODES;
        }
        // students from ID 101-300
        else if (personID >= 101 && personID <= 300) {
            maxRentals = STUDENT_CODES;
        }

        // make sure person has book checked out
        if (selectedPerson->data->checkCodeExists(selectedPerson->data, bookID, maxRentals)) {
            // start transaction for returns
            cout << selectedPerson << endl;
            selectedPerson->data->returnBook(selectedPerson->data, bookID, maxRentals);
            selectedBook->data->attemptToRent();

            cout << "***** Return succeeded. Check your info!" << endl;
            cout << selectedPerson << endl;
        }
        else {
            // TODO: put handler for too much books and the like
        }

    }
    else if (choice == 'n') {

    }
    else {
        // TODO: add error for choice input
    }
}

void menu4(PersonNodePtr* person, const int personTotal, BookNodePtr* books, const int bookTotal) {
    int userId;
    cout << "Enter id : ";
    cin >> userId;

    string name;
    cout << "Enter your name : ";
    cin >> name;

    // try to find and access book
    PersonNodePtr selectedPerson = personByID(person, userId);
    int countBooks = selectedPerson->data->getCount();
    if (countBooks == 1) {
        cout << "You rented " << countBooks << " book." << endl;
    }
    else {
        cout << "You rented " << countBooks << " books." << endl;
    }
    
    int maxCodes;
    // list all books from Teacher from ID 1-100
    if (userId >= 1 && userId <= 100) {
        maxCodes = TEACHER_CODES;
    }
    // list all books from Student from ID 101-300
    else if (userId >= 101 && userId <= 300) {
        maxCodes = STUDENT_CODES;
    }

    int* allCodes = selectedPerson->data->getCodes();
    for (int i = 0; i < maxCodes; i++) {
        if (allCodes[i] != 0) {
            BookNodePtr selectedBook = bookByCode(books, allCodes[i]);
            cout << "* " << selectedBook->data->getBookName() << " - ";

            // show age of children's books from ID 1001-2000
            if (allCodes[i] >= 1001 && allCodes[i] <= 2000) {
                cout << "age " << selectedBook->data->getAge() << endl;
            }
            // show publisher of CS books from ID 2001-3000
            else if (allCodes[i] >= 2001 && allCodes[i] <= 3000) {
                cout << "publisher " << selectedBook->data->getPublisher() << endl;
            }
            // show publish date of novel books from ID 3001-4000
            else if (allCodes[i] >= 3001 && allCodes[i] <= 4000) {
                cout << "publish date " << selectedBook->data->getPublishDate() << endl;
            }
        }
    }
    cout << endl;
}


int main()
{
    PersonNodePtr person[PERSON_LIST_TOTAL];
    BookNodePtr book[BOOK_LIST_TOTAL];
    initPersonList("programming_hw2\\person.txt", person, PERSON_LIST_TOTAL);
    initBookList("programming_hw2\\book.txt", book, BOOK_LIST_TOTAL);

    cout << person[0];

    // display menu
    bool stopLoop = false;

    while (!stopLoop) {
        cout << LINE_HEADER << endl;
        cout << "\tMenu" << endl;
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
        cout << "Select (1`6) : ";
        cin >> input;
        cout << endl;

        // handle menu thru function input
        switch (input) {
        case 1:
            menu1(book, BOOK_LIST_TOTAL);
            break;
        case 2:
            menu2(person, PERSON_LIST_TOTAL, book, BOOK_LIST_TOTAL);
            break;
        case 3:
            menu3(person, PERSON_LIST_TOTAL, book, BOOK_LIST_TOTAL);
            break;
        case 4:
            menu4(person, PERSON_LIST_TOTAL, book, BOOK_LIST_TOTAL);
            break;
        case 5:
            break;
        case 6:
            stopLoop = true;
            break;
        }
    }
    return 0;
}
