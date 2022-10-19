// 10380722, Anthony, Chen
// Date: 10/16/2022
// Lab11, Problem1

#include<iostream>
#include<cstdlib>
#include "Rational.h"

using namespace std;

int main()
{
	Rational r1, r2;
	char answer = 'y';
	while (answer == 'y') {
		cout << "Enter the first fraction (e.g. 3/4)  : "; cin >> r1;
		cout << "Enter the second fraction (e.g. 3/4) : "; cin >> r2;
		cout << "r1 : " << r1 << endl;
		cout << "r2 : " << r2 << endl << endl;
		cout << "r1 + r2 = " << r1 + r2 << endl;
		cout << "r1 - r2 = " << r1 - r2 << endl;
		cout << "r1 * r2 = " << r1 * r2 << endl;
		cout << "r1 / r2 = " << r1 / r2 << endl << endl;
		cout << "r1 == r2 -> " << (r1 == r2) << endl;
		cout << "r1 < r2  -> " << (r1 < r2) << endl;
		cout << "r1 <= r2 -> " << (r1 <= r2) << endl;
		cout << "r1 > r2  -> " << (r1 > r2) << endl;
		cout << "r1 >= r2 -> " << (r1 >= r2) << endl << endl;
		cout << "Again (y/n)? ";
		cin >> answer;
	}
	return 0;
}