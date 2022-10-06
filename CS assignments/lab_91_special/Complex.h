// Complex header file
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex();  // set both real and imaginary to 0 
	Complex(double, double);
	Complex addition(const Complex&);
	Complex subtraction(const Complex&);
	Complex multiplication(const Complex&);
	double getReal() const { return real; }
	double getImaginary() const { return imaginary; }
	void print();
private:
	double real;
	double imaginary;
};