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

// copy constructor
Polynomial::Polynomial(const Polynomial& poly) {
	int polyDeg = poly.degree;

	// make new heap for int to point to new coef address
	int* coefNew = new int[polyDeg];
	for (int i = 0; i < polyDeg; i++) {
		coefNew[i] = poly.coef[i];
	}
	coef = coefNew;
	degree = polyDeg;
}

// destructors
Polynomial::~Polynomial() {
	// remove coef from heap
	delete[] coef;
}

// functions
void Polynomial::operator= (const Polynomial& rightSide) {
	int polyDeg = rightSide.degree;

	// make new heap for int to point to new coef address
	int* coefNew = new int[polyDeg];
	for (int i = 0; i < polyDeg; i++) {
		coefNew[i] = rightSide.coef[i];
	}
	coef = coefNew;
	degree = rightSide.degree;
}