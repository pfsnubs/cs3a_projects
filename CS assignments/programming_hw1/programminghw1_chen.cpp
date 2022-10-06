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

// constants
const string LINE_HEADER = "----------------------------------------------------";
const string EQUAL_HEADER = "====================================================";
const string HALF_EQUAL_HEADER = "=========================";

// prototype fxns
void showAllCourses(int totalCourses, Course* courseList);

// functions
void showAllCourses(int totalCourses, Course* courseList){
  // go through all course list and print student info
  for (int i = 0; i < totalCourses; i++) {
      Course courseSelected = courseList[i];
      cout << "Course : " << courseSelected.getCourseName() << endl;
      cout << LINE_HEADER << endl;
      for (int j = 0; j < courseSelected.getTotalStudents(); j++) {
          // print out student data
          student studentSelected = courseSelected.studentList[j]; 
          cout << setw(10) << studentSelected.getId() <<
            setw(20) << studentSelected.getName() <<
            setw(5) << studentSelected.getScore()  << endl;
      } 
      cout << EQUAL_HEADER << endl;
  }
}

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

    cout << HALF_EQUAL_HEADER << " Menu " << HALF_EQUAL_HEADER << endl;
    cout << "1. Show all course lists" << endl;
    cout << "2. List of students who take all courses" << endl;
    cout << "3. List of students who take two courses" << endl;
    cout << "4. Print out top three scores for each course" << endl;

    int input;
    cout << "---> select : ";
    cin >> input;
    cout << endl;

    showAllCourses(totalCourses, courseList);
    

    return 0;
}
