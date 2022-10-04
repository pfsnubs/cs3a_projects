// 10380722, Anthony, Chen
// Date: 9/18/2022
// Lab6, Problem1

#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

// typedefs
typedef int* IntPtr;

// four function declarations
int maind()
{
    int* idPtr = nullptr;       // id array
    string* namePtr = nullptr;  // name array
    int* scorePtr = nullptr;    // score array
    char filename[20];
    cout << "Enter filename : ";
    cin >> filename;

    // open up file and iterate through, add all entries to pointers
    ifstream infile;
    infile.open(filename);

    // count number of entries to make for each array
    int count = 0;
    string line;
    while (!infile.eof()) {
        getline(infile, line);
        count++;
    }

    // create array of pointers with count entries
    idPtr = new int[count];
    namePtr = new string[count];
    scorePtr = new int[count];

    // output labels
    cout << "\tStudent List" << endl;
    cout << "------------------------------" << endl;

    // re-read file and assign vars 
    infile.clear(); // restart file reading 
    infile.seekg(0); // start back at line zero

    // Assign ptr value to array and print it out
    int iter = 0;
    while (!infile.eof()) {
        infile >> idPtr[iter] >> namePtr[iter] >> scorePtr[iter];
        cout << setw(6) << idPtr[iter] << setw(10) << namePtr[iter] << setw(6) << scorePtr[iter] << endl;
        iter++;
    }
    cout << "count : " << count << endl;


    // find max score number
    int max;
    int currentMax = 0;
    for (int i = 0; i < count; i++) {
        if (scorePtr[i] > currentMax) {
            currentMax = scorePtr[i];
        }
    }

    // update maxNo var
    max = currentMax;
    
    // print max score number
    cout << endl;
    cout << "*** Max score : " << max << endl;
    cout << endl;

    // print max list labels
    cout << "\tStudent with max score" << setw(10) << endl;
    cout << "----------------------------------------" << endl;

    // print out entries of max score students only
    for (int i = 0; i < count; i++) {
        if (scorePtr[i] == max) {
            cout << setw(6) << idPtr[i] << setw(10) << namePtr[i] << setw(6) << scorePtr[i] << endl;
        }
    }

    return 0;
}

