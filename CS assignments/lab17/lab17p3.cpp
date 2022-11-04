// 10380722, Anthony, Chen
// Date: 11/6/2022
// Lab17, Problem3

#include <iostream>
using namespace std;

void print(int* arr, int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* zero(int* arr, int arrLen, int* setArr, int setLen) {
    
    int streakIndex = -1;
    for (int i = 0; i < arrLen; i++) {
        // check beginning to look over
        if (arr[i] == setArr[0] && streakIndex == -1) {
            streakIndex = i;

            // check if streak is fulfilled
            int streakCount = 0;
            if (streakIndex + setLen <= arrLen) {
                // check if set aligns with one in streak
                for (int j = 0; j < setLen; j++) {
                    if (arr[streakIndex + j] == setArr[j]) {
                        streakCount++;
                    }
                }
            }

            // CASE: if a streak met, erase to zero from index
            if (streakCount == setLen) {
                for (int x = 0; x < setLen; x++) {
                    arr[streakIndex + x] = 0;
                }
            }
        }    

         // unlatch streak
        streakIndex = -1;
    }

    return arr;
}

int main()
{
    int a1[] = { 1, 2, 3, 4, 1, 2, 3, 4, 5 };
    int a2[] = { 2, 3, 4 };
    int b1[] = { 3, 3, 1, 3, 5, 3, 3, 3, 6, 7, 3, 3 };
    int b2[] = { 3, 3 };
    int c1[] = { 1, 2, 3, 1, 2, 3, 1, 1, 2, 3 };
    int c2[] = { 1 };
    int d1[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 2, 3 };
    int d2[] = { 1, 2, 3, 4, 5 };
    zero(a1, 9, a2, 3);
    zero(b1, 12, b2, 2);
    zero(c1, 10, c2, 1);
    zero(d1, 17, d2, 5);
    cout << "a1 : "; print(a1, 9);
    cout << "a2 : "; print(a2, 3);
    cout << "b1 : "; print(b1, 12);
    cout << "b2 : "; print(b2, 2);
    cout << "c1 : "; print(c1, 10);
    cout << "c2 : "; print(c2, 1);
    cout << "d1 : "; print(d1, 17);
    cout << "d2 : "; print(d2, 5);
}