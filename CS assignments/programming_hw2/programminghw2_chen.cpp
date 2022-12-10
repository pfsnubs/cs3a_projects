// 10380722, Anthony, Chen
// Date: 12/11/2022
// Homework Project 2

// include libraries
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

// include dependencies
#include "BookFiles\\Book.h"
#include "BookFiles\\BookNode.h"
#include "PersonFiles\\Person.h"
#include "PersonFiles\\PersonNode.h"

// constants
// header strings used for menu prints
const string LINE_HEADER = "-------------------------";
const string EQUAL_HEADER = "====================================================";
const string HALF_EQUAL_HEADER = "=========================";   
const int PERSON_LIST_TOTAL = 2;
const int BOOK_LIST_TOTAL = 3;
using namespace std;

// structs
struct ErrorMessage {
public:
    string error;
    ErrorMessage(string errMsg) {
        error = errMsg;
    };
};

// prototype fxns
/*
personByID()
    INPUT: 
           Takes in a dynamic array of PersonNode pointers person
           and an integer id to look for person
    OUTPUT:
           Searches through array lists of person to find
           the specific ID and returns back node pointer to
           the person node
*/
PersonNodePtr personByID(PersonNodePtr* person, int id);

/*
personByName()
    INPUT:
           Takes in a dynamic array of PersonNode pointers person
           and an string name to look for person
    OUTPUT:
           Searches through array lists of person to find
           the specific name and returns back node pointer to
           the person node
*/
PersonNodePtr personByName(PersonNodePtr* person, string name);

/*
bookByCode()
    INPUT:
           Takes in a dynamic array of BookNode pointers books
           and an int code to look for book based off code
    OUTPUT:
           Searches through array lists of books to find
           the specific BookNode and returns back a 
           BookNodePtr that points to the node
*/
BookNodePtr bookByCode(BookNodePtr* books, int code);

/*
bookByTitle()
    INPUT:
           Takes in a dynamic array of BookNode pointers books
           and an string title to find book title of
    OUTPUT:
           Searches through array lists of books to find
           the specific BookNode and returns back a
           BookNodePtr that points to the node based off 
           book title name
*/
BookNodePtr bookByTitle(BookNodePtr* books, string title);

/*
initPersonList()
    INPUT:
           Takes in a string dir that opens up to file directory,
           a pointer of PersonNodePtr person to access
           dynamic array of PersonNode categories
    OUTPUT:
           Reads through dir of file and places
           newly-created PersonNode class into 
           pointer of PersonNodePtr to fill in entries of
           its dynamic array
*/
void initPersonList(string dir, PersonNodePtr* person);

/*
initBookList()
    INPUT:
           Takes in a string dir that opens up to file directory,
           a pointer of BookNodePtr books to access
           dynamic array of BookNode categories
    OUTPUT:
           Reads through dir of file and places
           newly-created BookNode classes into
           entries of dynamic array in books
*/
void initBookList(string dir, BookNodePtr* books);

/*
menu1()
    INPUT:
           Takes in a pointer of BookNodePtr books
           aka the list of BookNodes and requests 
           user to input a book's code and title
    OUTPUT:
           Prints out all information of the
           specified book and its contents 
           of availability
*/
void menu1(BookNodePtr* books);

/*
menu2()
    INPUT:
           Takes in the list of PersonNodePtr dynamic array,
           and BookNodePtr dynamic array and
           requests user to enter user id and book title
    OUTPUT:
           Follows up with user to input a choice to
           rent a book or not based off book title,
           and lets them rent book to their collection
*/
void menu2(PersonNodePtr* person, BookNodePtr* books);

/*
menu3()
    INPUT:
           Takes in the list of PersonNodePtr dynamic array,
           and BookNodePtr dynamic array and
           requests user to enter user id and book code
    OUTPUT:
           Follows up with user to input a choice to
           return a book or not,
           and lets them place back book to the library
*/
void menu3(PersonNodePtr* person, BookNodePtr* books);

/*
menu4()
    INPUT:
           Takes in the list of PersonNodePtr dynamic array,
           and BookNodePtr dynamic array and
           requests user to enter user id and book code
    OUTPUT:
           Prints out information about user's
           total rented books and info on them
*/
void menu4(PersonNodePtr* person, BookNodePtr* books);

/*
menu5()
    INPUT:
           Takes in the list of BookNode dynamic array,
           and BookNode dynamic array and
           requests user to enter book code and book title
    OUTPUT:
           Prints out all books available in library
           and their code, title, availability, 
           and # of already-rented copies
*/
void menu5(BookNodePtr* books);

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

void initPersonList(string dir, PersonNodePtr* person) {    
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

void initBookList(string dir, BookNodePtr* books) {
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

void menu1(BookNodePtr* books) {
    BookNodePtr selectedBook = nullptr;

    // handle error inputs for user id and book code
    int codeSearch = -1;
    while (codeSearch == -1) {
        cout << "Enter code : ";
        try {
            cin >> codeSearch;

            // clear out chars if errored
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            selectedBook = bookByCode(books, codeSearch);

            // verify w/ title input
            string titleSearch = "";
            cout << "Enter title : ";
            cin >> titleSearch;

            // error check: book name must match title input
            if (selectedBook->data->getBookName() != titleSearch) {
                throw ErrorMessage("ID and title does not match, please try again.\n");
            }
        }
        catch (ErrorMessage err) {
            codeSearch = -1;
            cout << err.error << endl;
        }
    }    

    // look through entry to find book
    Book* bookPtr = selectedBook->data;
    string bookType;
    if (codeSearch >= 1001 && codeSearch <= 2000) {
        bookType = "children's";
    }
    // CS books from ID 2001-3000
    else if (codeSearch >= 2001 && codeSearch <= 3000) {
        bookType = "computer";
    }
    // novel books from ID 3001-4000
    else if (codeSearch >= 3001 && codeSearch <= 4000) {
        bookType = "novel";
    }

    cout << endl;
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
    cout << bookPtr->getAvailable() << " available, " << bookPtr->getRented() << " rented\n" << endl;
}

void menu2(PersonNodePtr* person, BookNodePtr* books) {
    PersonNodePtr selectedPerson = nullptr;
    BookNodePtr selectedBook = nullptr;
    int personID;
    int bookID;

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
        }
        catch (ErrorMessage err) {
            userId = -1;
            cout << err.error << endl;
        }
    }

    int maxRentals;
    // initialize max rentals person can rent
    // teachers from ID 1-100
    if (personID >= 1 && personID <= 100) {
        maxRentals = TEACHER_CODES;
    }
    // students from ID 101-300
    else if (personID >= 101 && personID <= 300) {
        maxRentals = STUDENT_CODES;
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
                throw ErrorMessage("All books of this code is unavailable to rent. Please try again.\n");
            }

            // error check: check if person has book already
            if (selectedPerson->data->checkCodeExists(selectedPerson->data, bookID, maxRentals)) {
                throw ErrorMessage("You cannot rent the same book twice. Please try again.\n");
            }
        }
        catch (ErrorMessage err) {
            titleSearch = "";
            cout << err.error << endl;
        }
    }

    // print out person's total books rented
    int personCount = selectedPerson->data->getCount();
    string personName = selectedPerson->data->getName();
    cout << endl;
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

            // proceed choices
            if (choice == 'y') {
                // error check: cannot exceed max rentals
                if (personCount == maxRentals) {
                    throw ErrorMessage("This person cannot rent any more books. Please try another choice.\n");
                }

                // start transaction for rental
                selectedPerson->data->rentBook(selectedPerson->data, bookID, maxRentals);
                selectedBook->data->attemptToRent();

                cout << "***** Rent succeeded. Check your info!\n" << endl;
            }
            else if (choice == 'n') {
                cout << "***** Rent cancelled.\n" << endl;
            }
        }
        catch (ErrorMessage err) {
            choice = ' ';
            cout << err.error << endl;
        }
    }    
}

void menu3(PersonNodePtr* person, BookNodePtr* books) {
    PersonNodePtr selectedPerson = nullptr;
    BookNodePtr selectedBook = nullptr;
    int personID;

    // handle error inputs for user id and book code
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
        }
        catch (ErrorMessage err) {
            userId = -1;
            cout << err.error << endl;
        }
    }

    // initialize max rentals person can rent
    int maxRentals;
    // teachers from ID 1-100
    if (personID >= 1 && personID <= 100) {
        maxRentals = TEACHER_CODES;
    }
    // students from ID 101-300
    else if (personID >= 101 && personID <= 300) {
        maxRentals = STUDENT_CODES;
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
            if (!selectedPerson->data->checkCodeExists(selectedPerson->data, bookCode, maxRentals)) {
                throw ErrorMessage("User does not have this book. Please try again.\n");
            }
        }
        catch (ErrorMessage err) {
            bookCode = -1;
            cout << err.error << endl;
        }
    }

    cout << endl;
    char choice = ' ';
    while (choice == ' ') {
        cout << "Do you want to return '" << selectedBook->data->getBookName() << "' (y/n)? ";
        try {
            cin >> choice;

            // error check: must be y or n char
            if (choice != 'y' && choice != 'n') {
                throw ErrorMessage("Invalid choice. Please enter again.\n");
            }

            // proceed choices
            if (choice == 'y') {
                // start transaction for returns
                selectedPerson->data->returnBook(selectedPerson->data, bookCode, maxRentals);
                selectedBook->data->attemptToRent();

                cout << "***** Return succeeded. Check your info!\n" << endl;
            }
            else if (choice == 'n') {
                cout << "***** Return cancelled.\n" << endl;
            }
        }
        catch (ErrorMessage err) {
            choice = ' ';
            cout << err.error << endl;
        }
    }
}

void menu4(PersonNodePtr* person, BookNodePtr* books) {
    // handle error inputs for user id and book title
    PersonNodePtr selectedPerson = nullptr;

    // handle error inputs for user id and user name
    int userId = -1;
    while (userId == -1) {
        cout << "Enter id : ";
        try {
            cin >> userId;

            // clear out chars if errored
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            selectedPerson = personByID(person, userId);

            // verify w/ name input
            string name = "";
            cout << "Enter your name : ";
            cin >> name;

            // error check: make sure name and ID of person aligns
            if (selectedPerson->data->getName() != name) {
                throw ErrorMessage("ID and name does not match, please try again.\n");
            }
        }
        catch (ErrorMessage err) {
            userId = -1;
            cout << err.error << endl;
        }
    }

    // initialize max rentals person can rent
    int maxRentals;
    // teachers from ID 1-100
    if (userId >= 1 && userId <= 100) {
        maxRentals = TEACHER_CODES;
    }
    // students from ID 101-300
    else if (userId >= 101 && userId <= 300) {
        maxRentals = STUDENT_CODES;
    }

    // try to find and access book
    int countBooks = selectedPerson->data->getCount();
    cout << endl;
    if (countBooks == 1) {
        cout << "You rented " << countBooks << " book." << endl;
    }
    else {
        cout << "You rented " << countBooks << " books." << endl;
    }

    int* allCodes = selectedPerson->data->getCodes();
    for (int i = 0; i < maxRentals; i++) {
        if (allCodes[i] != 0) {
            BookNodePtr selectedBook = bookByCode(books, allCodes[i]);
            cout << "* " << selectedBook->data->getBookName()
                << "(" << selectedBook->data->getCodeID() << ") - ";

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

void menu5(BookNodePtr* books) {
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
    cout << endl;
}

int main()
{
    PersonNodePtr person[PERSON_LIST_TOTAL];
    BookNodePtr book[BOOK_LIST_TOTAL];
    initPersonList("programming_hw2\\person.txt", person);
    initBookList("programming_hw2\\book.txt", book);

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
                    menu1(book);
                    break;
                case 2:
                    menu2(person, book);
                    break;
                case 3:
                    menu3(person, book);
                    break;
                case 4:
                    menu4(person, book);
                    break;
                case 5:
                    menu5(book);
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
