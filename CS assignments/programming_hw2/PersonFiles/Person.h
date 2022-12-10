#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#pragma once

// Constants
const int STUDENT_CODES = 2;
const int TEACHER_CODES = 3;
using namespace std;

class Person {
private:
    int id;         // ID number of student
    string name;    // name of student
    int count;      // total number of books rented
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

    // Functions

    /*
    Person::checkCodeExists()
        INPUT:
            Takes in a Person pointer p,
            an int bookID, and int maxCodes.
        OUTPUT:
            Iterates through Person pointer p's
            int* code and checks if bookID matches with
            the contents of int array, returns true if found
    */
    bool checkCodeExists(Person* p, int bookID, int maxCodes);

    /*
    Person::rentBook()
        INPUT:
            Takes in a Person pointer p,
            an int bookID, and int maxCodes.
        OUTPUT:
            Rents out a book by incrementing
            person's count and adding bookID
            to the person's int* code book list
            of available spot
    */
    void rentBook(Person* p, int bookID, int maxCodes);

    /*
    Person::returnBook()
        INPUT:
            Takes in a Person pointer p,
            an int bookID, and int maxCodes.
        OUTPUT:
            Returns a book for the person by
            decrementing person's count and 
            setting person's int* code entry for 
            that spot to be empty (= 0).
    */
    void returnBook(Person* p, int bookID, int maxCodes);
    
    friend ostream& operator << (ostream& os, Person& p) {
        os << p.id << " " << p.name << " " << p.count;
        return os;
    }

    // Virtual Functions
    virtual int* getCodes() { return 0; };
};


class Student
    : public Person
{
private:
    int code[STUDENT_CODES];    // Code list of books rented
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
    int code[TEACHER_CODES];    // Code list of books rented
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