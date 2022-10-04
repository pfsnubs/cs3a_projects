// 10380722, Anthony, Chen
// Date: 9/1/2022
// Lab2, Problem3

#include <iostream>

using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int ARR_LENGTH = 10;

void fillRandom(int arr[]) {
	// give every int array index a number
	for (int i = 0; i < ARR_LENGTH; i++) {
		int rollNo = (rand() % 50) + 1;
		arr[i] = rollNo;
	}
}

void printArr(int arr[]) {
	// easy print arrays
	for (int i = 0; i < ARR_LENGTH; i++) {
		cout << " " << arr[i] << " ";
	}
}

void swapPairs(int arr[]) {
	// swap every PAIRED value index
	// note: may need existence check for i+1 entries for scalable/odd arrays
	for (int i = 0; i < ARR_LENGTH; i= i + 2) {
		// make sure to save pair1 to set arr[i+1]'s entry as well
		swap(arr[i], arr[i + 1]);
	}
}

int main()
{
	srand(time(0));
	int A[ARR_LENGTH];

	// first fill in A with numbers and print it
	cout << "\tOriginal Array\t" << endl;
	cout << "--------------------------------------" << endl;
	fillRandom(A);
	printArr(A);
	cout << endl;


	// swap every pairs in array and print it
	cout << "\tAfter Swapping\t" << endl;
	cout << "--------------------------------------" << endl;
	swapPairs(A);
	printArr(A);

	return 0;
}