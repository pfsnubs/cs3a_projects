// 10380722, Anthony, Chen
// Date: 11/13/2022
// Lab 18, Problem 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int grade;
public:
    // constructor methods
    Student() {};
    Student(string name, int grade) {
        this->name = name;
        this->grade = grade;
    }

    // mutator methods
    void setName(string name) {
        this->name = name;
    }
    void setGrade(int grade) {
        this->grade = grade;
    }

    // accessor methods
    string getName() {
        return name;
    }
    int getGrade() {
        return grade;
    }
};

class HS_Student : public Student {
private:
    string activity;
public:
    HS_Student() {};
    HS_Student(string name, int grade, string activity) : Student(name, grade) {
        this->activity = activity;
    }

    // mutator methods
    void setActivity(string activity) {
        this->activity = activity;
    }

    // accessor methods
    string getActivity() {
        return activity;
    }
};

class MS_Student : public Student {
private:
    int mathScore, scienceScore;
public:
    MS_Student() {};
    MS_Student(string name, int grade, int mathScore, int scienceScore) : Student(name, grade) {
        this->mathScore = mathScore;
        this->scienceScore = scienceScore;
    }

    // mutator methods
    void setMathScore(int mathScore) {
        this->mathScore = mathScore;
    }
    void setScienceScore(int scienceScore) {
        this->scienceScore = scienceScore;
    }

    // accessor methods
    int getMathScore() {
        return mathScore;
    }
    int getScienceScore() {
        return scienceScore;
    }
};

int main()
{
    ifstream infile1;
    ifstream infile2;

    // init vars
    HS_Student* hStudents = NULL;
    int hStudentCount = 0;
    MS_Student* mStudents = NULL;
    int mStudentCount = 0;

    // HIGHSCHOOL STUDENTS
    {
        string fileName = "lab18\\HS.txt";
        infile2.open(fileName);
        if (infile2.fail()) {
            cout << "Input file opening failed." << endl;
            exit(1);
        }

        // count number of entries to make for each array
        string line;
        while (!infile2.eof()) {
            getline(infile2, line);
            hStudentCount++;
        }

        // create array of pointers with count entries
        hStudents = new HS_Student[hStudentCount];

        // re-read file again and assign vars 
        infile2.clear(); // restart file reading 
        infile2.seekg(0); // start back at first line
        int iter = 0;
        while (!infile2.eof()) {
            int grade;
            string name, activity;
            infile2 >> name >> grade >> activity;
            hStudents[iter] = HS_Student(name, grade, activity);
            iter++;
        }

        // sort array by lowest to highest grade
        for (int i = 0; i < hStudentCount - 1; i++) {
            if (hStudents[i].getGrade() > hStudents[i + 1].getGrade()) {
                HS_Student temp = hStudents[i];
                hStudents[i] = hStudents[i + 1];
                hStudents[i + 1] = temp;
                i = -1;
            }
        }

        // sort array by arranging by similar activities
        for (int i = 0; i < hStudentCount - 1; i++) {
            if (hStudents[i].getGrade() == hStudents[i + 1].getGrade()
                && hStudents[i].getActivity() < hStudents[i + 1].getActivity()) {
                HS_Student temp = hStudents[i];
                hStudents[i] = hStudents[i + 1];
                hStudents[i + 1] = temp;
                i = -1;
            }
        }

        // print out high school list of activities
        cout << "   High School Students   " << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        int prevLevel = -1;
        string activityShared;
        int totalInActivity = 0;
        for (int i = 0; i < hStudentCount; i++) {
            HS_Student currentStudent = hStudents[i];

            // create grade label on firsthand change (-1 > 9 > 10 > 11 > 12)
            if (prevLevel != currentStudent.getGrade()) {
                prevLevel = currentStudent.getGrade();
                cout << "Grade " << prevLevel << endl;
            }

            // count total of activity when change occurs ("" > "wrestling" > etc.)
            if (currentStudent.getActivity() != activityShared) {
                activityShared = currentStudent.getActivity();
                for (int j = 0; j < hStudentCount; j++) {
                    HS_Student sameStudent = hStudents[j];
                    if (prevLevel == sameStudent.getGrade()
                        && sameStudent.getActivity() == activityShared) {
                        totalInActivity++;
                    }
                }

                // print total and wipe counting values
                cout << "   " << activityShared << " : " << totalInActivity << endl;
                totalInActivity = 0;
            }
        }
    }

    cout << endl;
    cout << endl;

    //  MIDDLE SCHOOL STUDENTS 
    {
        string fileName = "lab18\\MS.txt";
        infile1.open(fileName);
        if (infile1.fail()) {
            cout << "Input file opening failed." << endl;
            exit(1);
        }

        // count number of entries to make for each array
        string line;
        while (!infile1.eof()) {
            getline(infile1, line);
            mStudentCount++;
        }

        // create array of pointers with count entries
        mStudents = new MS_Student[mStudentCount];

        // re-read file again and assign vars 
        infile1.clear(); // restart file reading 
        infile1.seekg(0); // start back at first line
        int iter = 0;
        while (!infile1.eof()) {
            int grade, mathScore, sciScore;
            string name;
            infile1 >> name >> grade >> mathScore >> sciScore;
            mStudents[iter] = MS_Student(name, grade, mathScore, sciScore);
            iter++;
        }

        // sort array by lowest to highest grade
        for (int i = 0; i < mStudentCount - 1; i++) {
            if (mStudents[i].getGrade() > mStudents[i + 1].getGrade()) {
                MS_Student temp = mStudents[i];
                mStudents[i] = mStudents[i + 1];
                mStudents[i + 1] = temp;
                i = -1;
            }
        }

        // print out middleschool list of average scores
        cout << "   Middle School Students   " << endl;
        cout << "----------------------------" << endl;
        int prevLevel = -1;
        int mathTotal = 0;
        int sciTotal = 0;
        int totalInGrade = 0;
        for (int i = 0; i < mStudentCount; i++) {
            MS_Student currentStudent = mStudents[i];
            if (prevLevel == -1) {
                // set lowest level as current viewing
                prevLevel = currentStudent.getGrade();
            }

            // if level changes or reached EOF, print out infos
            // and reset counting values
            if (prevLevel < currentStudent.getGrade() || i + 1 == mStudentCount) {
                double mathAvg = mathTotal / (double)totalInGrade;
                double sciAvg = sciTotal / (double)totalInGrade;
                cout << fixed;
                cout << setprecision(2);
                cout << setw(2) << prevLevel << "th grade : " << setw(6) << mathAvg << setw(8) << sciAvg << endl;

                // wipe counting values
                mathTotal = 0;
                sciTotal = 0;
                totalInGrade = 0;
                prevLevel = currentStudent.getGrade();
            }

            mathTotal += currentStudent.getMathScore();
            sciTotal += currentStudent.getScienceScore();
            totalInGrade++;
        }
    }

    return 0;
}