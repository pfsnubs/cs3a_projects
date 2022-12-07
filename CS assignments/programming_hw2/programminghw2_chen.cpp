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


struct ErrorMessage {
public:
    string error;
    ErrorMessage(string errMsg) {
        error = errMsg;
    };
};


// functions
PersonNodePtr personByID(PersonNodePtr* person, int id) {
    PersonNodePtr& teacherList = person[0];
    PersonNodePtr& studentList = person[1];

    // determine node list to search through first
    PersonNodePtr selectedNodeList = nullptr;
    // teachers from ID 1-100
    if (id >= 1 && id <= 100) {
        selectedNodeList = teacherList;
    }
    // students from ID 101-300
    else if (id >= 101 && id <= 300) {
        selectedNodeList = studentList;
    }

    PersonNodePtr selectedNode = nullptr;
    // try to find node in whichever list
    for (PersonNodePtr temp = selectedNodeList; temp != nullptr; temp = temp->link) {
        if (temp->data->getId() == id) {
            selectedNode = temp;
        }
    }

    // if person not found, error
    if (selectedNode == nullptr) {
        throw ErrorMessage("ID of person not found. Please enter again.\n");
    }

    return selectedNode;
}

PersonNodePtr personByName(PersonNodePtr* person, string name) {
    PersonNodePtr& teacherList = person[0];
    PersonNodePtr& studentList = person[1];
    PersonNodePtr selectedNode = nullptr;
    
    // try to find in teacher list
    for (PersonNodePtr temp = teacherList; temp != nullptr; temp = temp->link) {
        if (temp->data->getName() == name) {
            selectedNode = temp;
        }
    }

    // try to find in students list
    for (PersonNodePtr temp = studentList; temp != nullptr; temp = temp->link) {
        if (temp->data->getName() == name) {
            selectedNode = temp;
        }
    }

    // if person not found, error
    if (selectedNode == nullptr) {
        throw ErrorMessage("Name of person not found. Please enter again.\n");
    }

    return selectedNode;
}

BookNodePtr bookByCode(BookNodePtr* books, int code) {
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];
    BookNodePtr selectedBookList = nullptr;

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

    BookNodePtr selectedNode = nullptr;
    // try to find node in whichever list
    for (BookNodePtr temp = selectedBookList; temp != nullptr; temp = temp->link) {
        if (temp->data->getCodeID() == code) {
            selectedNode = temp;
        }
    }

    // if book not found, error
    if (selectedNode == nullptr) {
        throw ErrorMessage("Code of book not found. Please enter again.\n");
    }

    return selectedNode;
}

BookNodePtr bookByTitle(BookNodePtr* books, string title) {
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];
    BookNodePtr selectedNode = nullptr;

    // try to find in children's book list
    for (BookNodePtr temp = childBookList; temp != nullptr; temp = temp->link) {
        if (temp->data->getBookName() == title) {
            selectedNode = temp;
        }
    }

    // try to find in computer book list
    for (BookNodePtr temp = compBooklist; temp != nullptr; temp = temp->link) {
        if (temp->data->getBookName() == title) {
            selectedNode = temp;
        }
    }

    // try to find in novel list
    for (BookNodePtr temp = novelList; temp != nullptr; temp = temp->link) {
        if (temp->data->getBookName() == title) {
            selectedNode = temp;
        }
    }

    // if book not found, error
    if (selectedNode == nullptr) {
        throw ErrorMessage("Name of book not found. Please enter again.\n");
    }

    return selectedNode;
}


void initPersonList(string dir, PersonNodePtr* person, const int listTotal) {    
    // find heads of list
    PersonNodePtr& teacherList = person[0];
    PersonNodePtr& studentList = person[1];  
    teacherList = nullptr;
    studentList = nullptr;

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
            if (teacherList == nullptr) {
                teacherList = node;
            }
            else if (teacherList->data->getId() < node->data->getId()) {
                PersonNodePtr prev = nullptr;

                // traverse list from back
                for (PersonNodePtr temp = teacherList; temp != nullptr; temp = temp->link) {
                    if (temp->data->getId() < node->data->getId()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != nullptr) {
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
            if (studentList == nullptr) {
                studentList = node;
            }
            else if (studentList->data->getId() < node->data->getId()) {
                PersonNodePtr prev = nullptr;

                // traverse list from back
                for (PersonNodePtr temp = studentList; temp != nullptr; temp = temp->link) {
                    if (temp->data->getId() < node->data->getId()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != nullptr) {
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
    childBookList = nullptr;
    compBooklist = nullptr;
    novelList = nullptr;

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
            if (childBookList == nullptr) {
                childBookList = node;
            }
            else if (childBookList->data->getCodeID() < node->data->getCodeID()) {
                BookNodePtr prev = nullptr;

                // traverse list from back
                for (BookNodePtr temp = childBookList; temp != nullptr; temp = temp->link) {
                    if (temp->data->getCodeID() < node->data->getCodeID()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != nullptr) {
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
            if (compBooklist == nullptr) {
                compBooklist = node;
            }
            else if (compBooklist->data->getCodeID() < node->data->getCodeID()) {
                BookNodePtr prev = nullptr;

                // traverse list from back
                for (BookNodePtr temp = compBooklist; temp != nullptr; temp = temp->link) {
                    if (temp->data->getCodeID() < node->data->getCodeID()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != nullptr) {
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
            if (novelList == nullptr) {
                novelList = node;
            }
            else if (novelList->data->getCodeID() < node->data->getCodeID()) {
                BookNodePtr prev = nullptr;

                // traverse list from back
                for (BookNodePtr temp = novelList; temp != nullptr; temp = temp->link) {
                    if (temp->data->getCodeID() < node->data->getCodeID()) {
                        node->link = temp->link;
                        temp->link = node;

                        if (prev != nullptr) {
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
    Book* bookPtr = nullptr;
    for (BookNodePtr temp = selectedList; temp != nullptr; temp = temp->link) {
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
    PersonNodePtr selectedPerson = nullptr;
    BookNodePtr selectedBook = nullptr;
    int personID;
    int bookID;
    int maxRentals;

    // handle error inputs for user id and book title
    int userId = -1;
    while (userId == -1) {
        cout << "Enter id : ";
        try {
            cin >> userId;

            // clear out chars if errored
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            selectedPerson = personByID(person, userId);

            // initialize person ID
            personID = selectedPerson->data->getId();

            // initialize max rentals person can rent
            // teachers from ID 1-100
            if (personID >= 1 && personID <= 100) {
                maxRentals = TEACHER_CODES;
            }
            // students from ID 101-300
            else if (personID >= 101 && personID <= 300) {
                maxRentals = STUDENT_CODES;
            }
        }
        catch (ErrorMessage err) {
            userId = -1;
            cout << err.error << endl;
        }
    }

    string titleSearch = "";
    while (titleSearch == "") {
        cout << "Enter book title : ";
        try {
            cin >> titleSearch;
            selectedBook = bookByTitle(books, titleSearch);
            bookID = selectedBook->data->getCodeID();

            // find info on book and person
            int bookAvailables = selectedBook->data->getAvailable();

            // error check: check if book is available
            if (bookAvailables == 0) {
                throw ErrorMessage("All books of this code is unavailable to rent. Please try again.");
            }

            // error check: check if person has book already
            if (selectedPerson->data->checkCodeExists(selectedPerson->data, bookID, maxRentals)) {
                throw ErrorMessage("You cannot rent the same book twice. Please try again.");
            }
        }
        catch (ErrorMessage err) {
            titleSearch = "";
            cout << err.error << endl;
        }
    }

    
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
    
    // handle choice of book to rent or not
    char choice = ' ';
    while (choice == ' ') {
        cout << "Do you want to rent '" << selectedBook->data->getBookName() << "' (y/n)? ";
        try {
            cin >> choice;
            // error check: must be y or n char
            if (choice != 'y' && choice != 'n') {
                throw ErrorMessage("Invalid choice. Please enter again.\n");
            }

            // error check: cannot exceed max rentals
            if (personCount == maxRentals) {
                throw ErrorMessage("This person cannot rent any more books. Please try another choice.");
            }

            // proceed choices
            if (choice == 'y') {
                // start transaction for rental
                cout << selectedPerson << endl;
                selectedPerson->data->rentBook(selectedPerson->data, bookID, maxRentals);
                selectedBook->data->attemptToRent();

                cout << "***** Rent succeeded. Check your info!" << endl;
                cout << selectedPerson << endl;
            }
            else if (choice == 'n') {
                cout << "***** Rent cancelled." << endl;
            }
        }
        catch (ErrorMessage err) {
            choice = ' ';
            cout << err.error << endl;
        }
    }    
}

void menu3(PersonNodePtr* person, const int personTotal, BookNodePtr* books, const int bookTotal) {
    PersonNodePtr selectedPerson = nullptr;
    BookNodePtr selectedBook = nullptr;
    int personID;
    int bookID;
    int maxRentals;

    // handle error inputs for user id and book title
    int userId = -1;
    while (userId == -1) {
        cout << "Enter id : ";
        try {
            cin >> userId;

            // clear out chars if errored
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            selectedPerson = personByID(person, userId);

            // initialize person ID
            personID = selectedPerson->data->getId();

            // initialize max rentals person can rent
            // teachers from ID 1-100
            if (personID >= 1 && personID <= 100) {
                maxRentals = TEACHER_CODES;
            }
            // students from ID 101-300
            else if (personID >= 101 && personID <= 300) {
                maxRentals = STUDENT_CODES;
            }
        }
        catch (ErrorMessage err) {
            userId = -1;
            cout << err.error << endl;
        }
    }

    int bookCode = -1;
    while (bookCode == -1) {
        cout << "Enter book code to return : ";
        try {
            cin >> bookCode;

            // clear out chars if errored
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            selectedBook = bookByCode(books, bookCode);

            // error check: check if book is available
            if (selectedPerson->data->checkCodeExists(selectedPerson->data, bookCode, maxRentals)) {
                throw ErrorMessage("All books of this code is unavailable to rent. Please try again.");
            }
        }
        catch (ErrorMessage err) {
            bookCode = -1;
            cout << err.error << endl;
        }
    }

    char choice = ' ';
    while (choice == ' ') {
        cout << "Do you want to return '" << selectedBook->data->getBookName() << "' (y/n)? ";
        try {
            cin >> choice;

            // proceed choices
            if (choice == 'y') {
                // start transaction for returns
                cout << selectedPerson << endl;
                selectedPerson->data->returnBook(selectedPerson->data, bookID, maxRentals);
                selectedBook->data->attemptToRent();

                cout << "***** Return succeeded. Check your info!" << endl;
                cout << selectedPerson << endl;
            }
            else if (choice == 'n') {
                cout << "***** Return failed. Please try again." << endl;
            }
        }
        catch (ErrorMessage err) {
            choice = ' ';
            cout << err.error << endl;
        }
    }
}

void menu4(PersonNodePtr* person, const int personTotal, BookNodePtr* books, const int bookTotal) {
    // TODO: For enter id and name for the other menus too, make a function to check both name and code
    // handle error inputs for user id and book title
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

void menu5(BookNodePtr* books, const int listTotal) {
    // try to find and access book
    BookNodePtr& childBookList = books[0];
    BookNodePtr& compBooklist = books[1];
    BookNodePtr& novelList = books[2];

    // print out children's book list
    cout << endl;
    cout << EQUAL_HEADER << EQUAL_HEADER << endl;
    cout << "\t\t\t Children Books" << endl;
    cout << EQUAL_HEADER << EQUAL_HEADER << endl;
    cout << " code\t\t\t" << "title" << "\t\t\tage  available  rented" << endl;
    cout << LINE_HEADER << LINE_HEADER << LINE_HEADER << LINE_HEADER << endl;
    for (BookNodePtr temp = childBookList; temp != nullptr; temp = temp->link) {
        // replace underlines w/ spaces for names
        string bookName = temp->data->getBookName();
        for (int i = 0; i < bookName.length(); i++) {
            if (bookName[i] == '_') {
                bookName[i] = ' ';
            }
        }

        cout << setw(5) << temp->data->getCodeID()
            << setw(35) << bookName
            << setw(10) << temp->data->getAge()
            << setw(8) << temp->data->getAvailable()
            << setw(9) << temp->data->getRented() 
        << endl;
    }

    // print computer book list
    cout << endl;
    cout << endl;
    cout << EQUAL_HEADER << EQUAL_HEADER << endl;
    cout << "\t\t\t Computer Books" << endl;
    cout << EQUAL_HEADER << EQUAL_HEADER << endl;
    cout << " code\t\t\t" << "title" << "\t\t\tpublisher\tavailable    rented" << endl;
    cout << LINE_HEADER << LINE_HEADER << LINE_HEADER << LINE_HEADER << endl;
    for (BookNodePtr temp = compBooklist; temp != nullptr; temp = temp->link) {
        // replace underlines w/ spaces for names
        string bookName = temp->data->getBookName();
        for (int i = 0; i < bookName.length(); i++) {
            if (bookName[i] == '_') {
                bookName[i] = ' ';
            }
        }

        // replace dashes w/ spaces for publisher names
        string publisherName = temp->data->getPublisher();
        for (int i = 0; i < publisherName.length(); i++) {
            if (publisherName[i] == '-') {
                publisherName[i] = ' ';
            }
        }

        cout << setw(5) << temp->data->getCodeID()
            << setw(35) << bookName
            << setw(20) << publisherName
            << setw(10) << temp->data->getAvailable()
            << setw(10) << temp->data->getRented()
        << endl;
    }

    // print computer book list
    cout << endl;
    cout << endl;
    cout << EQUAL_HEADER << EQUAL_HEADER << endl;
    cout << "\t\t\t Novel Books" << endl;
    cout << EQUAL_HEADER << EQUAL_HEADER << endl;
    cout << " code\t\t\t" << "title" << "\t\t\tpublished date\tavailable    rented" << endl;
    cout << LINE_HEADER << LINE_HEADER << LINE_HEADER << LINE_HEADER << endl;
    for (BookNodePtr temp = novelList; temp != nullptr; temp = temp->link) {
        // replace underlines w/ spaces for names
        string bookName = temp->data->getBookName();
        for (int i = 0; i < bookName.length(); i++) {
            if (bookName[i] == '_') {
                bookName[i] = ' ';
            }
        }

        cout << setw(5) << temp->data->getCodeID()
            << setw(35) << bookName
            << setw(20) << temp->data->getPublishDate()
            << setw(10) << temp->data->getAvailable()
            << setw(10) << temp->data->getRented()
            << endl;
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

        int input = -1;
        while (input == -1) {
            try {
                // Prevent input erroring for integers
                // Source used: https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input
                // display input
                cout << endl;
                cout << "Select (1`6) : ";
                cin >> input;

                // clear out chars if errored
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                    menu5(book, BOOK_LIST_TOTAL);
                    break;
                case 6:
                    stopLoop = true;
                    break;
                default:
                    throw ErrorMessage("Invalid choice. Please enter again.\n");
                    break;
                }
            }
            catch (ErrorMessage err) {
                input = -1;
                cout << err.error << endl;
            }
        }
    }

    return 0;
}
