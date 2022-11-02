// 10380722, Anthony, Chen
// Date: 11/6/2022
// Lab16, Problem2

#include <iostream>
using namespace std;

const int MAX_NUMS = 10;
const int MAX_ROLL = 50;

void reverseArr(int* intArr, int index) {
    if (index > MAX_NUMS/2) return;
    int endHalf = (MAX_NUMS - 1) - index;
    int temp = intArr[index];
    intArr[index] = intArr[endHalf];
    intArr[endHalf] = temp;
    reverseArr(intArr, index + 1); 
}

void printArr(int* randArr) {
    cout << " ";
    for (int i = 0; i < MAX_NUMS; i++) {
        // init entries from 1-10
        cout << randArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int* randArr = new int[MAX_NUMS];
    for (int i = 0; i < MAX_NUMS; i++) {
        // init entries from 1-10
        randArr[i] = rand() % MAX_ROLL + 1;
    }

    srand(time(NULL));
    printArr(randArr);
    reverseArr(randArr, 0);
    cout << endl;
    printArr(randArr);
    return 0;
}
