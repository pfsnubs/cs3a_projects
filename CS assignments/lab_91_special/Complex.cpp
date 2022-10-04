#include "Complex.h"
using namespace std;

// constructors
Complex::Complex() {
	real = 0;
	imaginary = 0;
};

Complex::Complex(double realVal, double imagVal) {
	real = realVal;
	imaginary = imagVal;
};

// functions
Complex Complex::addition(const Complex& otherComp) {
	double otherReal = real + otherComp.getReal();
	double otherImag = imaginary + otherComp.getImaginary();
	Complex tempC(otherReal, otherImag);
	return tempC;
};

Complex Complex::subtraction(const Complex& otherComp) {
	double otherReal = real - otherComp.getReal();
	double otherImag = imaginary - otherComp.getImaginary();
	Complex tempC(otherReal, otherImag);
	return tempC;
};

Complex Complex::multiplication(const Complex& otherComp) {
	// do FOIL (real * real, real * imag, imag * real, imag * imag)
	double foilReals = real * otherComp.getReal();

	// foilHalf includes both real * imag and imag * real
	// distributing will always result in imaginary format
	double foilHalf = (real * otherComp.getImaginary()) + (otherComp.getReal() * imaginary);

	// multiplying imag * imag, returns -1 * the product, a real number
	double foilImags = -(imaginary * otherComp.getImaginary());

	// calculate reals and complex numbers separately
	double newReal = foilReals + foilImags;
	double newImag = foilHalf;
	Complex tempC(newReal, newImag);
	return tempC;
};

void Complex::print() {
	cout << getReal() << " + " << getImaginary() << "i";
}

