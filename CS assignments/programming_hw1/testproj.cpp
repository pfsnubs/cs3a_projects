//

//  main.cpp

//  programming hw1

//

//  Created by Ziyin Pang on 10/23/22.

//



#include <iostream>

#include <fstream>

#include <iomanip>

#include <string>

using namespace std;





class student

{

public:



    student();

    student(int id, string name, int score);



    void setId(int);

    void setName(string);

    void setScore(int);



    int getScore() { return score; }

    int getId() { return id; }

    string getName() { return name; }



private:

    int id;

    string name;

    int score;

};

student::student() {};

student::student(int id, string name, int score)

{

    this->id = id;

    this->name = name;

    this->score = score;

};



void student::setId(int new_id)

{

    id = new_id;

}

void student::setName(string new_name)

{

    name = new_name;

}

void student::setScore(int new_score)

{

    score = new_score;

}





struct course

{

    string courseName;

    int studentNumbers;

    student* studentList;

};



course readCourseFromFile(char filename[])

{

    string line;

    fstream myFile;



    myFile.open(filename);



    course* courseList;

    courseList = new course;



    myFile >> courseList->courseName >> courseList->studentNumbers;



    int student_number = courseList->studentNumbers;

    student* psList;

    psList = new student[student_number];



    int id;

    string name;

    int score;

    int i = 0;



    while (!myFile.eof())

    {

        myFile >> id >> name >> score;

        psList[i].setId(id);

        psList[i].setName(name);

        psList[i].setScore(score);

        i++;

    }



    myFile.close();



    return *courseList;

}









int main()

{
    char filename_1[20];

    char filename_2[20];

    char filename_3[20];

    int numberCourses;

    cout << "Enter the number of courses : ";

    cin >> numberCourses;

    cout << "Enter filename 1 :";

    cin >> filename_1;

    cout << "Enter filename 2 :";

    cin >> filename_2;

    cout << "Enter filename 3 :";

    cin >> filename_3;





    course course_1 = readCourseFromFile(filename_1);

    course course_2 = readCourseFromFile(filename_2);

    course course_3 = readCourseFromFile(filename_3);



    student* s1 = course_1.studentList;

    student* s2 = course_2.studentList;

    student* s3 = course_3.studentList;



    for (int i = 0; i < course_1.studentNumbers; i++)

    {

        cout << course_1.courseName << endl;

        cout << s1[i].getId() << "," << s1[i].getName() << "," << s1[i].getScore() << endl;

    }

    for (int j = 0; j < course_1.studentNumbers; j++)

    {

        cout << course_2.courseName << endl;

        cout << s1[j].getId() << "," << s1[j].getName() << "," << s1[j].getScore() << endl;

    }

    for (int k = 0; k < course_1.studentNumbers; k++)

    {

        cout << course_3.courseName << endl;

        cout << s1[k].getId() << "," << s1[k].getName() << "," << s1[k].getScore() << endl;

    }



}

