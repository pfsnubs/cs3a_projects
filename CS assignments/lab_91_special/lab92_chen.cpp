// 10380722, Anthony, Chen
// Date: 10/9/2022
// Lab9, Problem2

#include<iostream>
#include<cstdlib>
#include <iomanip>
#include "Complex.h"

using namespace std;

int main()
{
	int totalObjects = 2;
	Complex* complexArr = new Complex[totalObjects];
	for (int i = 0; i < 2; i++) {
		double realNum, imagNum;
		int displayNum = i + 1;
		cout << "Enter real and imaginary number for c" << displayNum << " : ";
		cin >> realNum >> imagNum;
		complexArr[i] = Complex(realNum, imagNum);
	}

	// get complex obj after maing both and print it out
	cout << endl;
	Complex c1 = complexArr[0];
	Complex c2 = complexArr[1];
	cout << "c1 = ";
	c1.print();
	cout << endl;
	cout << "c2 = ";
	c2.print();
	cout << endl;

	// using c1 as reference for object operations
	cout << endl;
	cout << setw(20) << left << "Sum" << ": ";
	Complex sumComp = c1.addition(c2);
	sumComp.print();
	cout << endl;
	
	cout << setw(20) << left << "Subtraction" << ": ";
	Complex subComp = c1.subtraction(c2);
	subComp.print();
	cout << endl;

	cout << setw(20) << left << "Multiplication" << ": ";
	Complex multComp = c1.multiplication(c2);
	multComp.print();
	cout << endl;

	return 0;
}
