#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// forward declaration for student
#include "student.h"

// structs
struct Course {
    string courseName;    // string name of course
    int totalStudents;    // int size of studentList
    student* studentList; // array of students

    // struct fxns
    Course();
    Course(string fileName);
    void setTotalStudents(int newTotal);
    void setCourseName(string newName);
    int getTotalStudents();
    string getCourseName();
    bool checkStudentExists(string name);
    student getStudent(string name);
};


