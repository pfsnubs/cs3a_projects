// 10380722, Anthony, Chen
// Date: 9/1/2022
// Lab2, Problem4

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// made a constant int = 50 since biggest array size is 50
const int TOTAL_STUDENTS = 50;

int main()
{
    // ask for file name
    ifstream infile;
    cout << "Enter a filename : ";
    string fileName;
    cin >> fileName;
    infile.open(fileName);
    cout << endl;

    // recieve inputs and print out student list
    cout << "** Students in " << fileName << " **" << endl;
    cout << "------------------------------------" << endl;

    // make arrays for scores of all students and their names
    string nameList[TOTAL_STUDENTS];
    int scoreList[TOTAL_STUDENTS];

    // open file and display list
    int score;
    int iter = 0;
    string first_name;
    while (!infile.eof()) {
        infile >> first_name >> score;
        cout << setw(10) << first_name << setw(10) << score << endl;

        // add student to list(s)
        nameList[iter] = first_name;
        scoreList[iter] = score;
        iter++;
    }
    cout << "------------------------------------" << endl;
    cout << endl;

    // go through entire list to find maximum number
    int number_of_scores = TOTAL_STUDENTS;
    int maxScore = scoreList[0];
    for (int x = 0; x < number_of_scores; x++) {
        if (scoreList[x] > maxScore) {
            maxScore = scoreList[x];
        }
    }
    cout << "** Max score : " << maxScore << endl;
    cout << endl;

    // find students in both lists for max score
    cout << "Students with max score" << endl;
    cout << "-----------------------" << endl;
    for (int index = 0; index < TOTAL_STUDENTS; index++) {
        if (scoreList[index] == maxScore) {
            cout << setw(6) << index << " : " << nameList[index] << endl;
        }
    }

    return 0;
}