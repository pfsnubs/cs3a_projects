// 10380722, Anthony, Chen
// Date: 11/13/2022
// Lab 19, Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Score
{
private:
    int cpp;
    int java;
    double average;
public:
    // constructors
    Score() : cpp(0), java(0), average(0) {};
    Score(int cpp, int java) {
        this->cpp = cpp;
        this->java = java;
        this->average = (cpp + java) / 2.0;
    }

    // copy constructor
    Score(const Score& scoreCopy) {
        // make new heap for score
        cpp = scoreCopy.cpp;
        java = scoreCopy.java;
        average = scoreCopy.average;
    }

    // destructors
    ~Score() {

    }

    // mutator methods
    void setCpp(int cpp) {
        this->cpp = cpp;
    }
    void setJava(int java) {
        this->java = java;
    }
    void setAverage(double average) {
        this->average = average;
    }

    // accessor methods
    int getCpp() {
        return cpp;
    }
    int getJava() {
        return java;
    }
    double getAverage() {
        return average;
    }
};

class Student
{
private:
    string name;
    Score* score;
public:
    // constructors
    Student() : name(""), score(NULL) {};

    Student(string name, Score* score) {
        this->name = name;
        Score* copyScore = score;
        // make new heap since we want to prevent address dependencies
        this->score = new Score(copyScore->getCpp(), copyScore->getJava());
    }

    // copy constructor
    Student(const Student& studentCopy) {
        Score* copyScore = studentCopy.score;
        // make new heap for incoming student
        score = new Score(copyScore->getCpp(), copyScore->getJava());
        name = studentCopy.name;
    }

    // destructors
    ~Student() {
        cout << "deleted " << name << " score " << endl;
        delete score; 
    }
    
    // mutator methods
    void setName(string name) {
        this->name = name;
    }
    void setScore(Score* score) {
        this->score = score;
    }

    // accessor methods
    string getName() {
        return name;
    }
    Score* getScores() {
        return score;
    }
};

int main()
{
    ifstream infile;
    string fileName;
    cout << "Enter the filename : ";
    cin >> fileName;
    infile.open(fileName);
    if (infile.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    // re-read file again and assign vars 
    Student** studentList = NULL;
    int totalStudents = 0;
    bool readTotal = false;
    int iter = 0;
    while (!infile.eof()) {
        if (!readTotal) {
            readTotal = true;
            infile >> totalStudents;

            // create array of students
            studentList = new Student*[totalStudents];
        }
        else {
            int java, cpp;
            string name;
            infile >> name >> cpp >> java;
            Score* studentScore = new Score(cpp, java);
            studentList[iter] = new Student(name, studentScore);
            iter++;
        }
    }

    // print unordered student list
    cout << "   Data from file" << endl;
    cout << "-----------------------" << endl;    
    for (int i = 0; i < totalStudents; i++) {
        Student* selected = studentList[i];
        Score* selectedScore = selected->getScores();
        cout << setw(8) << selected->getName()
            << setw(4)
            << setprecision(3) << (selectedScore)->getCpp()
            << setw(4)
            << setprecision(3) << (selectedScore)->getJava()
            << setw(6)
            << setprecision(3) << (selectedScore)->getAverage() << endl;
    }

    // arrange customers by their amount in descending order
    for (int i = 0; i < totalStudents - 1; i++) {
        Score* s1Score = (studentList)[i]->getScores();
        Score* s2Score = (studentList)[i + 1]->getScores();
        if ((s1Score)->getAverage() < (s2Score)->getAverage()) {
            Student* temp = studentList[i];
            studentList[i] = studentList[i + 1];
            studentList[i + 1] = temp;
            // reset loop to check again
            i = -1;
        }
    }

    // print sorted list
    cout << endl;
    cout << "    Sorted data" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < totalStudents; i++) {
        Student* selected = studentList[i];
        Score* selectedScore = (selected)->getScores();
        cout << setw(8) << (selected)->getName()
            << setw(4)
            << setprecision(3) << (selectedScore)->getCpp()
            << setw(6)
            << setprecision(3) << (selectedScore)->getJava()
            << setw(6)
            << setprecision(3) << (selectedScore)->getAverage() << endl;
    }
    return 0;
}