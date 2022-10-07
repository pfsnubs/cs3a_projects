// 10380722, Anthony, Chen
// Date: 10/16/2022
// Lab11, Problem1

#include<iostream>
#include<cstdlib>
#include "Rational.h"

using namespace std;

// friend fxns of Rational class

istream& operator>>(istream& is, Rational& a) {
	return is >> a.numerator >> a.denominator;
}

ostream& operator<<(ostream& os, const Rational& a) {
	return os << a.numerator << "/" << a.denominator << endl;
}

Rational operator+(const Rational& a, const Rational& b) {
	//Using (a/b + c/d = (a * d + b * c) / (b * d)) 
	Rational temp((b.numerator * a.denominator + a.numerator * b.denominator),
		(b.denominator * a.denominator));
	temp.simplify();
	return temp;
}

Rational operator-(const Rational& a, const Rational& b) {
	//Using (a/b + c/d = (b * c) - (a * d) / (b * d)) 
	Rational temp((a.numerator * b.denominator - b.numerator * a.denominator),
		(b.denominator * a.denominator));
	temp.simplify();
	return temp;
}

Rational operator*(const Rational& a, const Rational& b) {
	//Using (a/b * c/d = (a*c) / (b * d)) 
	Rational temp(((b.numerator * a.numerator)),
		(b.denominator * a.denominator));
	temp.simplify();
	return temp;
}

Rational operator/(const Rational& a, const Rational& b) {
	//Using (a/b / c/d = (a*d) / (b*c))
	Rational temp(((b.numerator * a.denominator)),
		(b.denominator * a.numerator));
	temp.simplify();
	return temp;
}

bool operator==(const Rational& a, const Rational& b) {
	Rational simplified_A = a;
	Rational simplified_B = b;
	simplified_A.simplify();
	simplified_B.simplify();
	return (simplified_A.numerator == simplified_B.numerator) 
		&& (simplified_A.denominator == simplified_B.denominator);
}

bool operator>(const Rational& a, const Rational& b) {
	Rational simplified_A = a;
	Rational simplified_B = b;
	simplified_A.simplify();
	simplified_B.simplify();
	return (simplified_A.numerator > simplified_B.numerator) 
		&& (simplified_A.denominator <= simplified_B.denominator);
}

bool operator<(const Rational& a, const Rational& b) {
	Rational simplified_A = a;
	Rational simplified_B = b;
	simplified_A.simplify();
	simplified_B.simplify();
	return (simplified_A.numerator < simplified_B.numerator)
		&& (simplified_A.denominator >= simplified_B.denominator);
}

bool operator>=(const Rational& a, const Rational& b) {
	Rational simplified_A = a;
	Rational simplified_B = b;
	simplified_A.simplify();
	simplified_B.simplify();
	return simplified_A == simplified_B
		|| simplified_A > simplified_B;
}

bool operator<=(const Rational& a, const Rational& b) {
	Rational simplified_A = a;
	Rational simplified_B = b;
	simplified_A.simplify();
	simplified_B.simplify();
	return simplified_A == simplified_B
		|| simplified_A < simplified_B;
}

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