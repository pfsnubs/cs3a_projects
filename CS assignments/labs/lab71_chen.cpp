// 10380722, Anthony, Chen
// Date: 9/25/2022
// Lab7, Problem1

#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

// structs
struct person {
    int id;
    string name;
    int score;
};

int main()
{
    char filename[20];
    cout << "Enter filename : ";
    cin >> filename;

    // read and print list of students
    int number_of_data;
    ifstream infile;
    infile.open(filename);

    // count number of entries to make for each array
    int count = 0;
    string line;
    while (!infile.eof()) {
        getline(infile, line);
        count++;
    }

    // set number of data value for later use
    number_of_data = count;

    // create array of pointers with count entries
    person* psArr = new person[count];

    // re-read file again and assign vars 
    infile.clear(); // restart file reading 
    infile.seekg(0); // start back at line zero
    int iter = 0;
    while (!infile.eof()) {
        infile >> psArr[iter].id >> psArr[iter].name >> psArr[iter].score;
        iter++;
    }

    cout << "\n  ID        Name       Score" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
        cout << psArr[i].id << setw(10) << psArr[i].name << setw(10) << psArr[i].score << endl;

    // get max score
    int max = 0;
    for (int i = 0; i < number_of_data; i++) {
        if (psArr[i].score > max) {
            max = psArr[i].score;
        }
    }

    // print out max scores
    cout << endl << "*****  Max score : " << max << endl;
    cout << endl;
    cout << "Persons who got max score" << endl;
    cout << "-------------------------" << endl;

    for (int i = 0; i < number_of_data; i++) {
        if (psArr[i].score == max) {
            cout << psArr[i].id << setw(10) << psArr[i].name << setw(10) << psArr[i].score << endl;
        }
    }

    return 0;
}
