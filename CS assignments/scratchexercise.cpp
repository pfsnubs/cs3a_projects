// 10380722, Anthony, Chen
// Date: 12/11/2022
// Extra Credit: Template Function

#include <iostream>

using namespace std;

template <class T>
int index_of_maximal(T* arr, int total) {
    int maxIndex = 0;
    for (int i = 0; i < total; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main()
{
    int index;
    int A[6] = { 10, 20, 30, 1, 2, 3 };
    index = index_of_maximal(A, 6);
    cout << "index : " << index << endl;
    double B[7] = { 3.3, 1.2, 0.5, 2.2, 4.5, 1.7 };
    index = index_of_maximal(B, 6);
    cout << "index : " << index << endl;
    char C[10] = { 'h', 'a', 'q', 'n', 'c', 'o', 'p', 'z', 's', 'j' };
    index = index_of_maximal(C, 10);
    cout << "index : " << index << endl;
    return 0;
}
