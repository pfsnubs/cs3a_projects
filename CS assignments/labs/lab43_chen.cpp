// 10380722, Anthony, Chen
// Date: 9/11/2022
// Lab4, Problem3

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// constants
const int MAX_NUMS = 10;
const int NUM_ROLL = 100;

void copyArr(int arrRef[], int arrCopyTo[]);

void copyArr(int arrRef[], int arrCopyTo[]) {
    for (int i = 0; i < MAX_NUMS; i++) {
        arrCopyTo[i] = arrRef[i];
    }
}

int main()
{
    srand(time(0));
    int numArr_A[MAX_NUMS];

    // Form and print table A (All random numbers)
    cout << "A : ";
    for (int i = 0; i < MAX_NUMS; i++) {
        numArr_A[i] = (rand() % NUM_ROLL);
        cout << numArr_A[i] << " ";
    }
    cout << endl;

    // Re-organize numArr table from highest to lowest in a duped array
    int arrDupe[MAX_NUMS];
    copyArr(numArr_A, arrDupe);

    // swap entries if current one is less than front one
    for (int i = 0; i < MAX_NUMS; i++) {
        // reset i loop from the very start after swap
        // (remember, at j = -1 due to j++)
        if (arrDupe[i] < arrDupe[i + 1]) {
            swap(arrDupe[i], arrDupe[i + 1]);
            i = -1;
        }
    }

    // Form and print table B (Highest to lowest, alternating between front and back)
    cout << "B : ";

    // Sort array by highest at the ends and lowest in the middle
    // We can use modulo on this operation since the previously-organized
    // array gave us the indexes of array from highest to lowest already
    int numArr_B[MAX_NUMS];

    // use placementIndex to designate array index placement of even numbers
    int placementIndex = 0;

    // use endingIndex to designate array index placement of odd numbers
    int endingIndex = 0;

    // use int k as the highest-to-lowest number 
    for (int k = 0; k < MAX_NUMS; k++) {
        // Determine highest/lowest placement by k modulo check
        if (k % 2 == 1) {
            // Every odd numbered index will be sent to the back
            // Add endingIndex first to get last indexes
            endingIndex++;
            numArr_B[MAX_NUMS - endingIndex] = arrDupe[k];
        }
        else {
            // access placementIndex and assign to current highest number in arrDupe
            numArr_B[placementIndex] = arrDupe[k];

            // increment placementIndex after setting, due to starting off at k = 0
            placementIndex++;
        }
    }

    // print out array B in all its glory
    for (int k = 0; k < MAX_NUMS; k++) {
        cout << numArr_B[k] << " ";
    }

    return 0;
}