// 10380722, Anthony, Chen
// Date: 8/30/2022
// Lab1, Problem2

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main2()
{
    ifstream infile;
    infile.open("data1.txt");
    int id, score;
    string first_name, last_name, full_name;
    int scoreArr[100];
    int i = 0;

    // recieve inputs
    cout << "   ID  First Name Last Name Score" << endl;
    cout << "---------------------------------" << endl;
    while (!infile.eof()) {
        infile >> id >> first_name >> last_name >> score;
        scoreArr[i++] = score;
        cout << id << setw(10) << first_name << setw(10) << last_name << setw(6) << score << endl;
    }
    
    int number_of_scores = i;
    int max = scoreArr[0];
    for (int x = 0; x < number_of_scores; x++) {
        if (scoreArr[x] > max) {
            max = scoreArr[x];
        }
    }
    cout << "Max no : " << max;

    return 0;
}