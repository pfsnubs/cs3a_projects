#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#pragma once

using namespace std;

class student {
private:
    int id;         // ID number of student
    string name;    // name of student
    int score;      // score of student

public:
    student();
    student(int newId, string newName, int newScore);

    // Mutators
    void setId(int newId);
    void setName(string newName);
    void setScore(int newScore);

    // Accessors
    int getId();
    string getName();
    int getScore();
};

