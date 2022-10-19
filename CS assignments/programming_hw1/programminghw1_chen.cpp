// 10380722, Anthony, Chen
// Date: 10/23/2022
// Homework Project 1

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "student.h"
#include "Course.h"

using namespace std;

// constants
// header strings used for menu prints
const string LINE_HEADER = "----------------------------------------------------";
const string EQUAL_HEADER = "====================================================";
const string HALF_EQUAL_HEADER = "=========================";   

const int MAX_COURSES = 3;      // max courses to input for menu
const int MAX_PLACEMENTS = 3;   // show top X students of a course list

// prototype fxns
int countStudentExistence(Course* courseList, string studentName);
void showAllCourses(int totalCourses, Course* courseList);                      // menu1
void student_AllCourses(int totalCourses, Course* courseList, int maxStudents); // menu2

void sameCourseList(Course* courseList, Course course, Course courseCompare, 
    student*& sameRoster, int& rosterSize, int maxEntry); 
void twoCourse_ScorePrint(int courseTotal, Course course1, Course course2, 
    student* rosterList);
void student_TwoCourses(int totalCourses, Course* courseList, int maxStudents); // menu3

void swapEntries(int* arr, int entry1, int entry2);
void sortHiToLow(int*& scoreArr, int scoreSize);
void student_TopThree(int totalCourses, Course* courseList);                    // menu4

// functions
int countStudentExistence(Course* courseList, string studentName) {
    // general function used to check a student inside multiple classes
    int coursesEntered = 0;
    for (int i = 0; i < MAX_COURSES; i++) {
        Course courseSelected = courseList[i];
        if (courseSelected.checkStudentExists(studentName)) {
            coursesEntered++;
        }
    }
    return coursesEntered;
}

// menu1
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

// menu2
void student_AllCourses(int totalCourses, Course* courseList, int maxStudents) {
    // go through all courses and count occurrence of a certain student
    // we know every student has a unique name so we don't need to worry
    // about dupes, just make a loop through each course list
    // we can run through just one course b/c they are guaranteed to be in all

    // grab all-course students
    Course courseSelected = courseList[0];
    student* allCourseStudents = new student[maxStudents];
    int ac_Index = 0;
    for (int i = 0; i < courseSelected.getTotalStudents(); i++) {
        student studentSelected = courseSelected.studentList[i];
        string studentName = studentSelected.getName();
        int coursesEntered = countStudentExistence(courseList, studentName);

        // add student to array of students in all courses
        if (coursesEntered == MAX_COURSES) {
            allCourseStudents[ac_Index] = studentSelected;
            ac_Index++;
        }
    }

    cout << "There are " << ac_Index << " students who take all 3 courses" << endl;
    cout << LINE_HEADER << endl;

    // run again through to print the student info
    for (int i = 0; i < ac_Index; i++) {
        student studentSelected = allCourseStudents[i];
        string studentName = studentSelected.getName();
        int studentID = studentSelected.getId();

        // set up name and ID and add courses after
        cout << setw(5) << studentID
            << setw(10) << studentName;

        // collect student scores from all courses 
        // and add to print sentence
        for (int i = 0; i < totalCourses; i++) {
            Course courseSelected = courseList[i];
            student foundStudent = courseSelected.getStudent(studentName);
            cout << setw(5) << courseSelected.getCourseName()  
                << " (" << foundStudent.getScore() << ") ";
        }
        cout << endl;
    }
}

// menu3
void sameCourseList(Course* courseList, Course course, Course courseCompare, 
    student*& sameRoster, int& rosterSize, int maxEntry) {
    // function used to detect and gather student of same courses
    // also adds student to roster list and increases roster size

    for (int i = 0; i < course.getTotalStudents(); i++) {
        student studentSelected = course.studentList[i];
        string studentName = studentSelected.getName();
        int coursesEntered = countStudentExistence(courseList, studentName);

        // make sure player has only two courses, sort by proper arrays
        if (coursesEntered == maxEntry) {
            if (courseCompare.checkStudentExists(studentName)) {
                sameRoster[rosterSize] = studentSelected;
                rosterSize++;
            }
        }
    }
}

void twoCourse_ScorePrint(int courseTotal, Course course1, Course course2, student* rosterList) {
    // prints scores of the course array given for menu3
    string strTemplate = "There are " + to_string(courseTotal)
        + " students who take " + course1.getCourseName()
        + " and " + course2.getCourseName() + "\n";
    cout << strTemplate;
    cout << LINE_HEADER << endl;
    for (int i = 0; i < courseTotal; i++) {
        student studentSelected = rosterList[i];
        string studentName = studentSelected.getName();
        int studentID = studentSelected.getId();
        cout << setw(10) << studentID
            << setw(10) << studentName;

        // get respective student scores from separate classes
        student course0Student = course1.getStudent(studentName);
        student course2Student = course2.getStudent(studentName);
        cout << setw(10) << course1.getCourseName()
            << " (" << course0Student.getScore() << ") ";
        cout << setw(10) << course2.getCourseName()
            << " (" << course2Student.getScore() << ") ";
        cout << endl;
    }
    cout << endl;
}

void student_TwoCourses(int totalCourses, Course* courseList, int maxStudents) {
    // get students that are strictly in two courses
    Course course0 = courseList[0];
    Course course1 = courseList[1];
    Course course2 = courseList[2];

    // set up ints to say # of students in two classes
    int course0and1_Total = 0;
    int course0and2_Total = 0;
    int course1and2_Total = 0;
    
    // create array of students to get student infos of two classes
    student* course01_Students = new student[maxStudents];
    student* course02_Students = new student[maxStudents];
    student* course12_Students = new student[maxStudents];

    // go through students of course1 (dealing with course1-2)
    int numberToCheck = 2;
    sameCourseList(courseList, course0, course1, course01_Students, course0and1_Total, numberToCheck);
    sameCourseList(courseList, course0, course2, course02_Students, course0and2_Total, numberToCheck);
    sameCourseList(courseList, course1, course2, course12_Students, course1and2_Total, numberToCheck);

    // print scores from function
    twoCourse_ScorePrint(course0and1_Total, course0, course1, course01_Students);
    twoCourse_ScorePrint(course0and2_Total, course0, course2, course02_Students);
    twoCourse_ScorePrint(course1and2_Total, course1, course2, course12_Students);   
}

// menu4

void swapEntries(int* arr, int entry1, int entry2) {
    // swaps entries of an int array
    int temp = arr[entry1];
    arr[entry1] = arr[entry2];
    arr[entry2] = temp;
}

void sortHiToLow(int*& scoreArr, int scoreSize) {
    // sorts integers by highest to lowest in scoreArr
    for (int i = 0; i < scoreSize; i++) {
        if (scoreArr[i] < scoreArr[i + 1]) {
            swapEntries(scoreArr, i, i + 1);
            i = -1; // reset to the far back to double check again
        }
    }
}

void student_TopThree(int totalCourses, Course* courseList) {
    // sort top three students of each class by using an index array 
    // that points to the scores for the respective student
    for (int i = 0; i < totalCourses; i++) {
        Course courseSelected = courseList[i];
        student* studentList = courseSelected.studentList;
        int totalStudents = courseSelected.getTotalStudents();
        int* scoreList = new int[totalStudents];
        
        // gather student scores and pour into scoreList
        for (int i = 0; i < totalStudents; i++) {
            scoreList[i] = courseSelected.studentList[i].getScore();
        }

        // use sorting function to sort scores by top to bottom
        sortHiToLow(scoreList, totalStudents);

        // run through the score for each student score
        cout << " [ " << courseSelected.getCourseName()
            << " Top Three Scores ] " << endl;
        int scorePlacement = 1;
        for (int i = 0; i < totalStudents; i++) {
            // show score marking with placement, make sure only show top three
            if (scoreList[i] != scoreList[i + 1] && scorePlacement <= MAX_PLACEMENTS) {
                cout << scorePlacement << ". " << scoreList[i] << endl;
                scorePlacement++;

                // print out score of students underneath placements
                for (int j = 0; j < totalStudents; j++) {
                    string studentName = studentList[j].getName();
                    int studentID = studentList[j].getId();
                    int studentScore = studentList[j].getScore();

                    // print id and name entry of score shared in placement
                    if (scoreList[i] == studentList[j].getScore()) {
                        cout << setw(3) << " " << studentID << setw(10) << studentName << endl;
                    }
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    int totalCourses;
    cout << "Enter number of courses : ";
    cin >> totalCourses;

    // set up filename prompt and make an array for courses
    Course* courseList = new Course[totalCourses];
    for (int i = 0; i < totalCourses; i++) {
        string fileName;

        // name it i+1 since counting starts at 1 
        cout << "Enter filename " << i + 1 << " : ";
        cin >> fileName;
        courseList[i] = Course(fileName);
    }
    cout << endl;
    cout << endl;

    // get maximum total number of students from all courses
    // used for array purposes
    int maxStudents = 0;
    for (int i = 0; i < totalCourses; i++) {
        int studentTotal = courseList[i].getTotalStudents();
        if (maxStudents < studentTotal) {
            maxStudents = studentTotal;
        }
    }
    
    // display menu
    cout << HALF_EQUAL_HEADER << " Menu " << HALF_EQUAL_HEADER << endl;
    cout << "1. Show all course lists" << endl;
    cout << "2. List of students who take all courses" << endl;
    cout << "3. List of students who take two courses" << endl;
    cout << "4. Print out top three scores for each course" << endl;

    // display input
    int input;
    cout << "---> select : ";
    cin >> input;
    cout << endl;

    // handle menu thru function input
    switch (input) {
    case 1:
        showAllCourses(totalCourses, courseList);
        break;
    case 2:
        student_AllCourses(totalCourses, courseList, maxStudents);
        break;
    case 3:
        student_TwoCourses(totalCourses, courseList, maxStudents);
        break;
    case 4:
        student_TopThree(totalCourses, courseList);
        break;
    }
    return 0;
}
