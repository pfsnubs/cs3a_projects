// 10380722, Anthony, Chen
// Date: 9/13/2022
// Lab5, Problem1

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// constants
const int MAX_ROLL = 15;

// prototypes
void fillArray(int[], int);
void printArray(int[], int);

// runtime
int maind()
{
	const int N = 10;
	int A[N] = { 0 };
	srand(time(NULL));
	fillArray(A, 10);
	printArray(A, 10);
	return 0;
}

void fillArray(int A[], int size)
{
	// we want every entry to be a UNIQUE random number
	for (int i = 0; i < size; i++) {
		int randNo = (rand() % MAX_ROLL) + 1;

		// run a loop to change randNo if it exists in A[] already
		for (int j = 0; j < size; j++) {
			// check array if number exists, if so then reroll again and start over
			if (A[j] == randNo) {
				randNo = (rand() % MAX_ROLL) + 1;
				j = -1; // reset at -1 due to j++
			}
		}

		// once a unique number, set as entry
		A[i] = randNo;
	}
}

void printArray(int A[], int size)
{
	// print out all entries in A
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}
}