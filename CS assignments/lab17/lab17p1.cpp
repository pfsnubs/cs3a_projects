// 10380722, Anthony, Chen
// Date: 11/6/2022
// Lab17, Problem1

#include <iostream>
using namespace std;

int binaryConvert(int num) {
    int bin = 0;
    int streak = 0;
    
    // slice num until it reaches 1
    while (num >= 1) {
        // cash in at binary slot
        if (num % 2 == 1) {
            bin += pow(10, streak);
        }

        // slice num by 2, incr. place streak
        num /= 2;
        streak++;
    }

    return bin;
}

int main()
{
    char choice = 'y';

    // repeat menu
    while (choice != 'n') {
        int num;
        cout << "Enter one positive integer : ";
        cin >> num;

        int bin = binaryConvert(num);
        cout << "Decimal " << num << " -> Binary " << bin << endl;

        cout << "More (y/n) ? ";
        cin >> choice;
        cout << endl;

    }
    
    return 0;
}
