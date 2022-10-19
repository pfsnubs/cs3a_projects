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

    // Constructors
    Course();
    Course(string fileName);

    // Mutators
    void setTotalStudents(int newTotal);
    void setCourseName(string newName);

    // Accessors
    int getTotalStudents();
    string getCourseName();

    /*
    Course::checkStudentExists()
        INPUT:
            Takes in a string name (a student's name)
            to search through studentList through.
        OUTPUT:
            Iterates through studentList to find
            a student's name matched with name
            and returns true if found, false otherwise
    */
    bool checkStudentExists(string name);

    /*
    Course::getStudent()
        INPUT:
            Takes in a string name, a student's name
            to find through studentList
        OUTPUT:
            Iterates through studentList and checks if
            the name is found in the array, and
            returns back the student object of the name found
            in studentList.
    */
    student getStudent(string name);
};


