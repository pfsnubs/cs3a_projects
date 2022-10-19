// 10380722, Anthony, Chen
// Date: 9/18/2022
// Lab6, Problem2

#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

// typedefs
typedef int* IntPtr;

// prototypes
int readDataFromFile(char filename[], IntPtr* idPtr, string** namePtr, IntPtr* scorePtr);

void printData(IntPtr id, string* name, IntPtr score, int count);

void findMax(IntPtr score, int* maxNo, int count);

void printMaxList(IntPtr idPtr, string* name, IntPtr score, int count, int max);


// functions
int readDataFromFile(char filename[], IntPtr* idPtr, string** namePtr, IntPtr* scorePtr) {
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
    *idPtr = new int[count];
    *namePtr = new string[count];
    *scorePtr = new int[count];

    // output labels
    cout << "\tStudent List" << endl;
    cout << "------------------------------" << endl;

    // re-read file and assign vars 
    infile.clear(); // restart file reading 
    infile.seekg(0); // start back at line zero
    int iter = 0;
    while (!infile.eof()) {
        infile >> (*idPtr)[iter] >> (*namePtr)[iter] >> (*scorePtr)[iter];
        iter++;
    }

    return count;
}

void printData(IntPtr id, string* name, IntPtr score, int count) {
    // print data
    for (int i = 0; i < count; i++) {
        cout << setw(6) << id[i] << setw(10) << name[i] << setw(6) << score[i] << endl;
    }
}


void findMax(IntPtr score, int* maxNo, int count) {
    int currentMax = 0;
    for (int i = 0; i < count; i++) {
        if (score[i] > currentMax) {
            currentMax = score[i];
        }
    }

    // update maxNo var
    *maxNo = currentMax;

    cout << endl;
    cout << "*** Max score : " << *maxNo << endl;
    cout << endl;
}

void printMaxList(IntPtr id, string* name, IntPtr score, int count, int max) {
    // print max list labels
    cout << "\tStudent with max score" << setw(10) << endl;
    cout << "----------------------------------------" << endl;

    // print out entries of max score students only
    for (int i = 0; i < count; i++) {
        if (score[i] == max) {
            cout << setw(6) << id[i] << setw(10) << name[i] << setw(6) << score[i] << endl;
        }
    }
}


// four function declarations
int main()
{
    int* id = nullptr;       // id array
    string* name = nullptr;  // name array
    int* score = nullptr;    // score array
    char filename[20];
    cout << "Enter filename : ";
    cin >> filename;
    int count = readDataFromFile(filename, &id, &name, &score);
    cout << "count : " << count << endl;
    printData(id, name, score, count);
    int max;
    findMax(score, &max, count);
    printMaxList(id, name, score, count, max);
    return 0;
}
// four function definitions (readDataFromFile, printData, findMax, printMaxList)

