#include "student.h"
using namespace std;

// student Class constructors
Person::Person() {
    id = 0;
    name = "New Student";
    count = 0;
}

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
    count = newCount;
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