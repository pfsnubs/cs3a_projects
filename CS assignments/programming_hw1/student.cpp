#include "student.h"
using namespace std;

// student Class constructors
student::student() {
    id = 0;
    name = "New Student";
    score = 0;
}

student::student(int newId, string newName, int newScore) {
    id = newId;
    name = newName;
    score = newScore;
}

// student functions
void student::setId(int newId) {
    id = newId;
};

void student::setName(string newName) {
    name = newName;
};

void student::setScore(int newScore) {
    score = newScore;
};

int student::getId() {
    return id;
};

string student::getName() {
    return name;
};

int student::getScore() {
    return score;
};