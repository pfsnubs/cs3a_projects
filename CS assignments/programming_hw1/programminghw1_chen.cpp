// 10380722, Anthony, Chen
// Date: 10/23/2022
// Homework1, Problem1

/*
1.You should use struct Course and class Student
2.You should create a structure dynamically(I will test your
code with different input files).
3.You should create a structure using a function.
4.Each menu should be implemented as a function.
5.Make your main code as neat and readable as possible.
6.Use reference and pointers appropriately.
7.Documentation is needed (see the rubric).

For menu4, if all students have the same score, they should all be printed as the top score students. There are no second or third place scores.

If there are only first and second place scores, you only need to print them out. There is no third place score.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "student.h";
#include "Course.h";

using namespace std;

int main()
{
    int totalCourses;
    cout << "Enter number of courses : ";
    cin >> totalCourses;
    cout << endl;

    // set up filename prompt and make an array for courses
    Course* courseList = new Course[totalCourses];
    for (int i = 0; i < totalCourses; i++) {
        string fileName;

        // name it i+1 since counting starts at 1 
        cout << "Enter filename " << i + 1 << " : ";
        cin >> fileName;
        courseList[i] = Course(fileName);
        cout << endl;
    }

    for (int i = 0; i < courseList[0].getTotalStudents(); i++) {
        cout << "clist " << courseList[0].studentList[i].getName() << endl;
    }

    return 0;
}
