#include "Person.h"

// Constants
using namespace std;

// student Class constructors
Person::Person(int newId, string newName, int newCount) {
    id = newId;
    name = newName;
    count = newCount;
}

// student functions

// Mutator methods
void Person::setId(int newId) {
    id = newId;
};
void Person::setName(string newName) {
    name = newName;
};
void Person::setCount(int newScore) {
    count = newScore;
};


// Accessor methods
int Person::getId() {
    return id;
};
string Person::getName() {
    return name;
};
int Person::getCount() {
    return count;
};

// Other functions
bool Person::checkCodeExists(Person* p, int bookID, int maxCodes) {
    bool found = false;
    for (int i = 0; i < maxCodes; i++) {
        if (p->getCodes()[i] == bookID) {
            found = true;
            break;
        }
    }
    return found;
}

void Person::rentBook(Person* p, int bookID, int maxCodes) {
    // increase count of rentals and add book ID to codes
    p->setCount(p->getCount() + 1);
    for (int i = 0; i < maxCodes; i++) {
        if (p->getCodes()[i] == 0) {
            p->getCodes()[i] = bookID;
            break;
        }
    }
}

void Person::returnBook(Person* p, int bookID, int maxCodes) {
    // decrease count of rentals and remove book ID from codes
    p->setCount(p->getCount() - 1);
    for (int i = 0; i < maxCodes; i++) {
        if (p->getCodes()[i] == bookID) {
            p->getCodes()[i] = 0;
            break;
        }
    }
}