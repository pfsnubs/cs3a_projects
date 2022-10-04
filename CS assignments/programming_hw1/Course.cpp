#include "Course.h"
#include <sstream>
using namespace std;

Course::Course() {
    courseName = "";
    totalStudents = 0;
    studentList = NULL;
};

// Course constructor
Course::Course(string fileName) {
    ifstream infile;
    infile.open(fileName);

    cout << "TESTING 1" << endl;
    // count number of entries to make for each array
    int count = -1; // start at -1 since first line is course data
    string line;
    while (!infile.eof()) {
        if (count == -1) {
            // take in first line as Course data info
            string newCourseName;
            int newTotalStudents;
            infile >> newCourseName >> newTotalStudents;
            setCourseName(newCourseName);
            setTotalStudents(newTotalStudents);
        }
        else {
            // skip line
            getline(infile, line);
        }

        count++;
    }
    cout << "TESTING 2" << endl;

    // create array of pointers with count entries
    studentList = new student[count];
    studentList[0] = student(1, "bruh", 2);

    cout << "TESTING 3" << count << endl;
    // re-read file again and assign vars 
    infile.clear(); // restart file reading 
    infile.seekg(0); // start back at first line
    int iter = 0;
    while (!infile.eof()) {
        string line;
        getline(infile, line);

        // skip first line (b/c of course data line)
        if (iter != 0) {
            // access line and split into multiple datatypes using stringstream
            // source: https://stackoverflow.com/questions/68396962/how-to-split-strings-in-c-like-in-python
            stringstream ss;
            ss << line;

            // use set function to put values into student obj
            int idRead, scoreRead;
            string nameRead;
            ss >> idRead >> nameRead >> scoreRead;
            //cout << "ITER " << idRead << nameRead << scoreRead << endl;
            studentList[iter] = student(idRead, nameRead, scoreRead);
        }
        iter++;
    }

}

// course fxns

void Course::setTotalStudents(int newTotal) {
    totalStudents = newTotal;
};

void Course::setCourseName(string newName) {
    courseName = newName;
};

int Course::getTotalStudents() {
    return totalStudents;
};

string Course::getCourseName() {
    return courseName;
};