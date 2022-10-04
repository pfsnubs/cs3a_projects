// 10380722, Anthony, Chen
// Date: 9/6/2022
// Lab3, Problem1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ARR_SIZE = 50;

int main()
{
    int arrNums[MAX_ARR_SIZE];
    int userInputSize;
    cout << "What's your list size (<= 50) : ";
    cin >> userInputSize;
    cout << "Enter your number whose total number is " << userInputSize << endl;

    // gather input of ints into a table
    for (int i = 0; i < userInputSize; i++) {
        cin >> arrNums[i];
    }
    cout << endl;
    cout << "-----------------------------------------" << endl;

    // Sort array by highest to slow by swapping
    for (int x = 0; x < userInputSize; x++) {
        if (arrNums[x] < arrNums[x + 1]) {
            swap(arrNums[x], arrNums[x + 1]);
            // Reset loop back to the start, not 0 
            // b/c it will be 0 + 1 next loop otherwise
            x = -1; 
        }
    }

    // print N and counts label
    cout << "\tN\tcounts" << endl;

    // Count duplicates and print out result N
    // Technically, since we organized the array from above using swap,
    // all we need to do is just count through and clear after each different number
    int dupesTotal = 1;
    for (int j = 0; j < userInputSize; j++) {
        // Count duplicates
        if (arrNums[j] == arrNums[j + 1]) {
            dupesTotal++;
        }
        else {
            // save entry and break dupe streak
            cout << "\t" << arrNums[j] << "\t" << dupesTotal << endl;

            // increase dupeEntry and wipe dupe total for next streak
            dupesTotal = 1;
        }
    }


    return 0;
}