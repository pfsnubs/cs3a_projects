// 10380722, Anthony, Chen
// Date: 9/25/2022
// Lab8, Problem1

#include<iostream>
#include<cstdlib>

using namespace std;

// classes
class Rational
{
public:
	Rational();      // set numerator to 0 and denominator 1
	Rational(int, int);
	Rational add(const Rational&);
	Rational subtract(const Rational&);
	Rational multiply(const Rational&);
	Rational divide(const Rational&);
	void print();
	void simplify(); // make 2/4 --> 1/2
private:
	int numerator;
	int denominator;
};

// Rational constructors
Rational::Rational() {
	numerator = 0;
	denominator = 1;
};

Rational::Rational(int num, int den) {
	numerator = num;
	denominator = den;
};

// Rational functions
Rational Rational::add(const Rational& r) {
	//Using (a/b + c/d = (a * d + b * c) / (b * d)) 
	Rational temp((numerator * r.denominator + r.numerator * denominator),
		(denominator * r.denominator));
	return temp;
}

Rational Rational::subtract(const Rational& r) {
	//Using (a/b - c/d = (a * d - b * c) / (b * d)) 
	Rational temp((numerator * r.denominator - r.numerator * denominator),
		(denominator * r.denominator));
	return temp;
}

Rational Rational::multiply(const Rational& r) {
	//Using (a/b * c/d = (a*c) / (b * d)) 
	Rational temp(((numerator * r.numerator)),
		(denominator * r.denominator));
	return temp;
}

Rational Rational::divide(const Rational& r) {
	//Using (a/b / c/d = (a*d) / (b*c))
	Rational temp(((numerator * r.denominator)),
		(denominator * r.numerator));
	return temp;
}

void Rational::print() {
	simplify();
	cout << numerator << "/" << denominator << endl;
}

void Rational::simplify() {
	// start from highest number 
	// and decrement to find lowest common denom.
	int lcd = 1;

	// stop loop it reaches the max numerator/denom
	while (lcd <= max(numerator, denominator)) {
		// typecast lcd to make sure division isnt truncated
		double numeratorLCD = numerator / (double)lcd;
		double denominatorLCD = denominator / (double)lcd;

		// check if lcd works by checking 
		// if it cleanly cuts both numbers
		//cout << lcd << " " << numeratorLCD << " " << floor(numeratorLCD) << endl;
		if (numeratorLCD == floor(numeratorLCD) 
			&& denominatorLCD == floor(denominatorLCD)) {
			numerator /= lcd;
			denominator /= lcd;
		}
		lcd++;
	}
}

int main()
{
	int num1, denom1, num2, denom2;
	cout << "Enter numerator and denominator for r1 : ";
	cin >> num1 >> denom1;
	cout << "Enter numerator and denominator for r2 : ";
	cin >> num2 >> denom2;
	Rational r1(num1, denom1);
	Rational r2(num2, denom2);
	Rational sum = r1.add(r2);
	Rational dif = r1.subtract(r2);
	Rational mul = r1.multiply(r2);
	Rational div = r1.divide(r2);
	cout << endl;
	cout << "Sum : "; sum.print();
	cout << "Dif : "; dif.print();
	cout << "Mul : "; mul.print();
	cout << "Div : "; div.print();
	return 0;
}
