#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// forward declaration for student
#include "student.h"

// structs
struct Course {
    string courseName;
    int totalStudents;
    student* studentList;
    Course();
    Course(string fileName);
    void setTotalStudents(int newTotal);
    void setCourseName(string newName);
    int getTotalStudents();
    string getCourseName();
};


