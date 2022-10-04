#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#pragma once

using namespace std;

class student {
private:
    int id;
    string name;
    int score;
public:
    student();
    student(int newId, string newName, int newScore);
    void setId(int newId);
    void setName(string newName);
    void setScore(int newScore);
    int getId();
    string getName();
    int getScore();
};

