#include "Book.h"
using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Book constructors
/*
Book::Book() {
    code = 0;
    title = "";
    available = 0;
    rented = 0;
};
*/

Book::Book(int code, string title, int available, int rented) {
    this->code = code;
    this->title = title;
    this->available = available;
    this->rented = rented;
}

// course fxns

// mutators
void Book::setCodeID(int newID) {
    code = newID;
};
void Book::setBookName(string newName) {
    title = newName;
};
void Book::setAvailable(int newAvailable) {
    available = newAvailable;
};
void Book::setRented(int newRented) {
    rented = newRented;
};

// accessors
int Book::getCodeID() {
    return code;
};
string Book::getBookName() {
    return title;
};
int Book::getAvailable() {
    return available;
};
int Book::getRented() {
    return rented;
};

// Other
void Book::attemptToRent() {
    // adjust rent and availability if rentable
    available--;
    rented++;
};

void Book::attemptToReturn() {
    // adjust rent and availability if returning
    available++;
    rented--;
};