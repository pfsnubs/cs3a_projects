#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#pragma once

using namespace std;

class Person {
private:
    int id;         // ID number of student
    string name;    // name of student
    int count;      // total number of books rented

public:
    // Constructors
    Person();
    Person(int newId, string newName, int newCount);

    // Mutators
    void setId(int newId);
    void setName(string newName);
    void setCount(int newCount);

    // Accessors
    int getId();
    string getName();
    int getCount();
};

class Student
    : protected Person
{
private:
    int code[2];
public:
    // Constructors
    Student(int newId, string newName, int newCount, int* code) 
        :Person(int newId, string newName, int newCount){
        this->code = code;
    };

    // Accessors
    int* getCodes() {
        return code;
    };
};

class Teacher
    : protected Person
{
private:
    int code[3];
public:
    // Constructors
    Teacher(int newId, string newName, int newCount, int* code) 
        :Person(int newId, string newName, int newCount){
        this->code = code;
    };

    // Accessors
    int* getCodes() {
        return code;
    };
};