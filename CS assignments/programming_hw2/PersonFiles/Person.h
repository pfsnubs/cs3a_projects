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

    friend ostream& operator << (ostream& os, const Person& p) {
        os << p.id << " " << p.name << " " << p.count;
        return os;
    }
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