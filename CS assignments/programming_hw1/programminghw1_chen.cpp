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
const int MAX_COURSES = 3;

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
      cout << endl;
  }
}

// prototype fxn
void student_AllCourses(int totalCourses, Course* courseList);
void student_AllCourses(int totalCourses, Course* courseList) {
    // go through all courses and count occurrence of a certain student
    // we know every student has a unique name so we don't need to worry
    // about dupes, just make a loop through each course list
   // we can run through just one course b/c they are guaranteed to be in all

    // grab number of all-course students
    int totalStudents = 0;
    Course courseSelected = courseList[0];
    for (int j = 0; j < courseSelected.getTotalStudents(); j++) {
        student studentSelected = courseSelected.studentList[j];
        string studentName = studentSelected.getName();
        int coursesEntered = 0;

        // loop through other courses to find existence
        for (int i = 0; i < totalCourses; i++) {
            // make sure course searched is not the one we are in
            Course courseSelected = courseList[i];
            if (courseSelected.checkStudentExists(studentName)) {
                coursesEntered++;
            }
        }
        if (coursesEntered == MAX_COURSES) {
            totalStudents++;
        }
    }

    cout << "There are " << totalStudents << " who take all 3 courses" << endl;
    cout << LINE_HEADER << endl;

    // run again through to get student info
    for (int j = 0; j < courseSelected.getTotalStudents(); j++) {
        student studentSelected = courseSelected.studentList[j];
        string studentName = studentSelected.getName();
        int coursesEntered = 0;

        // loop through other courses to find existence
        int scoreCpp = 0;
        int scoreJava = 0;
        int scorePy = 0;
        for (int i = 0; i < totalCourses; i++) {
            // make sure course searched is not the one we are in
            Course courseSelected = courseList[i];
            if (courseSelected.checkStudentExists(studentName)) {
                coursesEntered++;
                if (courseSelected.getCourseName() == "C++") {
                    scoreCpp = 
                }
            }
        }

        if (coursesEntered == MAX_COURSES) {
            cout << setw(10) << studentSelected.getId() <<
                setw(20) << studentSelected.getName() <<
                setw(5) << studentSelected.getScore() << endl;
        }
    }
    
    
}

void student_TwoCourses(int totalCourses, Course* courseList);
void student_TwoCourses(int totalCourses, Course* courseList) {
    // go through all courses and count occurrence of a certain student
    // we know every student has a unique name so we don't need to worry
    // about dupes, just make a loop through each course list

    int maxCount = 2;
    for (int i = 0; i < totalCourses; i++) {
        Course courseSelected = courseList[i];
        for (int j = 0; j < courseSelected.getTotalStudents(); j++) {
            student studentSelected = courseSelected.studentList[j];
            string studentName = studentSelected.getName();
            int coursesEntered = 0;

            // loop through other courses to find existence
            for (int i = 0; i < totalCourses; i++) {
                // make sure course searched is not the one we are in
                Course courseSelected = courseList[i];
                if (courseSelected.checkStudentExists(studentName)) {
                    coursesEntered++;
                }
            }

            if (coursesEntered == maxCount) {
                cout << "student max " << studentName << endl;
            }


        }

    }
}


void student_TopThree(int totalCourses, Course* courseList);
void student_TopThree(int totalCourses, Course* courseList) {
    // go through all courses and count occurrence of a certain student
    // we know every student has a unique name so we don't need to worry
    // about dupes, just make a loop through each course list
    for (int i = 0; i < totalCourses; i++) {
        Course courseSelected = courseList[i];
        for (int j = 0; j < courseSelected.getTotalStudents(); j++) {
            student studentSelected = courseSelected.studentList[j];
            string studentName = studentSelected.getName();
            int coursesEntered = 0;

            // loop through other courses to find existence
            for (int i = 0; i < totalCourses; i++) {
                // make sure course searched is not the one we are in
                Course courseSelected = courseList[i];
                if (courseSelected.checkStudentExists(studentName)) {
                    coursesEntered++;
                }
            }

            if (coursesEntered == MAX_COURSES) {
                cout << "student max " << studentName << endl;
            }


        }

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

    switch (input) {
    case 1:
        showAllCourses(totalCourses, courseList);
        break;
    case 2:
        student_AllCourses(totalCourses, courseList);
        break;
    case 3:
        student_TwoCourses(totalCourses, courseList);
        break;
    case 4:
        student_TopThree(totalCourses, courseList);
        break;
    }

    
    

    return 0;
}
