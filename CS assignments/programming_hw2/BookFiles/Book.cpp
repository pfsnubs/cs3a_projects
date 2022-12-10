#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

// Constants
using namespace std;

// Book constructors
Book::Book(int code, string title, int available, int rented) {
    this->code = code;
    this->title = title;
    this->available = available;
    this->rented = rented;
}

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

// Functions
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