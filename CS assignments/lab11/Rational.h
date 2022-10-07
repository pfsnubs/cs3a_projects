// Rational class header file
#include<iostream>
#include<cstdlib>
using namespace std;
class Rational
{
public:
	Rational();
	Rational(int);
	Rational(int, int);
	friend istream& operator >>(istream&, Rational&);// input function
	friend ostream& operator<<(ostream&, const Rational&);// output function
	// Arithmetic operators (+, -, *, /)
	friend Rational operator+(const Rational&, const Rational&);
	friend Rational operator-(const Rational&, const Rational&);
	friend Rational operator*(const Rational&, const Rational&);
	friend Rational operator/(const Rational&, const Rational&);
	// Relational operators (==, >, <, >=, <=)
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator>(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);
	friend bool operator>=(const Rational&, const Rational&);
	friend bool operator<=(const Rational&, const Rational&);
private:
	int numerator;
	int denominator;
	void simplify(); // make 2/4 --> 1/2
};