// 10380722, Anthony, Chen
// Date: 9/13/2022
// Lab5, Problem2

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// prototypes
void deleteRepeats(char A[], int& size);

// runtime
int main()
{
	int size = 8;
	char alpha[10];

	// set all chars in alpha array
	alpha[0] = 'a';
	alpha[1] = 'b';
	alpha[2] = 'c';
	alpha[3] = 'a';
	alpha[4] = 'd';
	alpha[5] = 'a';
	alpha[6] = 'c';
	alpha[7] = 'e';
	
	// call fxn and print out result
	deleteRepeats(alpha, size);
	cout << "After deleting repeat" << endl;
	for (int i = 0; i < size; ++i)
		cout << alpha[i] << endl;

	return 0;
}

void deleteRepeats(char A[], int& size){
	// iterate through char array and remove entry
	for (int i = 0; i < size; i++) {
		// use i as an entry to check duplicates
		// run the array again to find the dupes and remove it
		for (int j = 0; j < size; j++) {
			// check char value match 
			// and make sure not to remove current char
			if (A[i] == A[j] && i != j) {
				A[j] = '\0';
			}
		}
	}

	// after clearing out loop, swap the place of it with
	// remaining letters so that nullspace doesnt appear in between
	for (int x = 0; x < size; x++) {
		if (A[x] == '\0') {
			// once found a nullspace, find a letter to replace it with
			for (int y = x; y < size; y++) {
				if (A[y] != '\0') {
					swap(A[x], A[y]);
					break;
				}
			}			
		}
	}

	// recalculate size because we just want 
	// the size of the array of only letters
	int newSize = 0;
	for (int k = 0; k < size; k++) {
		if (A[k] != '\0') {
			newSize++;
		}
	}

	// re-assign size to newSize to print only letters
	size = newSize;
}