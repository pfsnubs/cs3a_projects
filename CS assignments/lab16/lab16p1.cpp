// 10380722, Anthony, Chen
// Date: 11/6/2022
// Lab16, Problem1

#include <iostream>
using namespace std;

int pow(int n, int e) {
    if (e == 0) return 1;
    return n * pow(n, e - 1);
}

int main()
{
    int baseNo, exp;
    cout << "Enter a base number: ";
    cin >> baseNo;

    cout << "Enter an exponent: ";
    cin >> exp;

    cout << baseNo << "^" << exp << " = " << pow(baseNo, exp);
    return 0;
}
