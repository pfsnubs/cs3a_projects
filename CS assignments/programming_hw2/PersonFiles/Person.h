#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#pragma once

using namespace std;

const int STUDENT_CODES = 2;
const int TEACHER_CODES = 3;

class Person {
private:
    int id;         // ID number of student
    string name;    // name of student
    int count;      // total number of books rented
    string classType;
public:
    // Constructors
    Person(){};
    Person(int newId, string newName, int newCount);

    // Mutators
    void setId(int newId);
    void setName(string newName);
    void setCount(int newCount);

    // Accessors
    int getId();
    string getName();
    int getCount();

    // functions
    bool checkCodeExists(Person* p, int bookID, int maxCodes) {
        bool found = false;
        for (int i = 0; i < maxCodes; i++) {
            if (p->getCodes()[i] == bookID) {
                found = true;
            }
        }
        return found;
    }

    void rentBook(Person* p, int bookID, int maxCodes) {        
        // increase count of rentals and add book ID to codes
        p->setCount(p->getCount() + 1);
        for (int i = 0; i < maxCodes; i++) {
            if (p->getCodes()[i] == 0) {
                p->getCodes()[i] = bookID;
            }
        }
    }

    void returnBook(Person* p, int bookID, int maxCodes) {
        // decrease count of rentals and remove book ID from codes
        p->setCount(p->getCount() - 1);
        for (int i = 0; i < maxCodes; i++) {
            if (p->getCodes()[i] == bookID) {
                p->getCodes()[i] = 0;
            }
        }
    }
    
    friend ostream& operator << (ostream& os, Person& p) {
        os << p.id << " " << p.name << " " << p.count;
        for (int i = 0; i < 2; i++) {
            os << "CODE " << p.getCodes()[i] << endl;
        }
        return os;
    }

    // Custom functions
    virtual int* getCodes() { return 0; };
};


class Student
    : public Person
{
private:
    int code[STUDENT_CODES];
public:
    // Constructors
    Student() {};
    Student(int newId, string newName, int newCount, int* code)
        :Person(newId, newName, newCount) {
        for (int i = 0; i < STUDENT_CODES; i++) {
            this->code[i] = code[i];
        }
    };

    // Accessors
    int* getCodes() {
        return code;
    };
};

class Teacher
    : public Person
{
private:
    int code[TEACHER_CODES];
public:
    // Constructors
    Teacher() {};
    Teacher(int newId, string newName, int newCount, int* code)
        :Person(newId, newName, newCount) {
        for (int i = 0; i < TEACHER_CODES; i++) {
            this->code[i] = code[i];
        }
    };

    // Accessors
    int* getCodes() {
        return code;
    };
};