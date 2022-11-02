// 10380722, Anthony, Chen
// Date: 11/6/2022
// Lab16, Problem2

#include <iostream>
using namespace std;

const int MAX_NUMS = 10;

int addSum(int* intArr, int index) {
    if (index + 1 > MAX_NUMS) return 0;
    return intArr[index] += addSum(intArr, index + 1);
}

int main()
{
    int* randArr = new int[MAX_NUMS];
    srand(time(NULL));

    cout << " ";
    for (int i = 0; i < MAX_NUMS; i++) {
        // init entries from 1-10
        randArr[i] = rand() % MAX_NUMS + 1;
        cout << randArr[i] << " ";
    }
    cout << endl;

    // recursively add entry sums
    cout << "sum : " << addSum(randArr, 0);
    return 0;
}
