// Polynomial cpp file
#include "Polynomial.h"
using namespace std;

// constructors
Polynomial::Polynomial() {};

Polynomial::Polynomial(int d) {
	coef = NULL;
	degree = d;
};

Polynomial::Polynomial(int* c, int d) {
	coef = c;
	degree = d;
};

// functions
int* Polynomial::getCoef() {
	return coef;
}

int Polynomial::getDegree() {
	return degree;
}

void Polynomial::print() {
	for (int polyDeg = degree; polyDeg > -1; polyDeg--) {
		int polyCoef = (coef)[polyDeg];
		if (polyCoef != 0) {
			cout << polyCoef << "x^" << polyDeg;

			// Print add sign until last polynomial
			if (polyDeg - 1 > -1) {
				cout << " + ";
			}
		}
	}
	cout << endl;
}