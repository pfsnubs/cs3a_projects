// 10380722, Anthony, Chen
// Date: 9/25/2022
// Lab7, Problem2

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

// prototypes
person* readDataFromFile(char[], int*);
int findMax(person*, int);
void printMaxScorePersons(person*, int, int);

// fxns
person* readDataFromFile(char filename[], int* number_of_data) {
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
    *number_of_data = count;

    // create array of pointers with count entries
    person* psList = new person[count];

    // re-read file again and assign vars 
    infile.clear(); // restart file reading 
    infile.seekg(0); // start back at line zero
    int iter = 0;
    while (!infile.eof()) {
        infile >> psList[iter].id >> psList[iter].name >> psList[iter].score;
        iter++;
    }

    return psList;
}

int findMax(person* psArr, int numData) {
    int currentMax = 0;
    for (int i = 0; i < numData; i++) {
        if (psArr[i].score > currentMax) {
            currentMax = psArr[i].score;
        }
    }
    return currentMax;
}

void printMaxScorePersons(person* psArr, int max, int numData) {
    for (int i = 0; i < numData; i++) {
        if (psArr[i].score == max) {
            cout << psArr[i].id << setw(10) << psArr[i].name << setw(10) << psArr[i].score << endl;
        }
    }        
}

int main()
{
	char filename[20];
	cout << "Enter filename : ";
	cin >> filename;
	int number_of_data;
	person* ps = readDataFromFile(filename, &number_of_data);
	cout << "\n  ID        Name       Score" << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < number_of_data; i++)
		cout << ps[i].id << setw(10) << ps[i].name << setw(10) << ps[i].score << endl;
	int max = findMax(ps, number_of_data);
	cout << endl << "*****  Max score : " << max << endl;
	cout << endl;
	cout << "Persons who got max score" << endl;
	cout << "-------------------------" << endl;
	printMaxScorePersons(ps, max, number_of_data);
	return 0;
}
