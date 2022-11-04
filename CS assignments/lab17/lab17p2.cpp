// 10380722, Anthony, Chen
// Date: 11/6/2022
// Lab17, Problem2

#include <iostream>
using namespace std;

int rbinaryConvert(int num, int bin, int streak) {
    if (num < 1) return bin;
    if (num % 2 == 1) {
        bin += pow(10, streak);
    }
    return rbinaryConvert(num/2, bin, ++streak);
}

int main()
{
    char choice = 'y';

    // repeat menu
    while (choice != 'n') {
        int num;
        cout << "Enter one positive integer : ";
        cin >> num;

        int bin = rbinaryConvert(num, 0, 0);
        cout << "Decimal " << num << " -> Binary " << bin << endl;

        cout << "More (y/n) ? ";
        cin >> choice;
        cout << endl;

    }

    return 0;
}
