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

// friend functions
Polynomial operator+ (Polynomial x, Polynomial y) {
    int xDeg = x.degree;
    int yDeg = y.degree;
    int* xCoeffs = x.coef;
    int* yCoeffs = y.coef;

    // assume either degrees for equal cases, 
    // otherwise use one of them
    int highest = xDeg;
    if (xDeg < yDeg) {
        highest = yDeg;
    }
    else {
        highest = xDeg;
    }

    // iterate through all and add entries
    int* newCoeffs = new int[highest];
    for (int i = 0; i < highest; i++) {
        // assume values are zero if exceeds degree term
        int intX = 0;
        if (i < xDeg) {
            intX = xCoeffs[i];
        }
        int intY = 0;
        if (i < yDeg) {
            intY = yCoeffs[i];
        };
        newCoeffs[i] = intX + intY;
    }
    return Polynomial(newCoeffs, highest);
}

Polynomial operator- (Polynomial x, Polynomial y) {
    int xDeg = x.degree;
    int yDeg = y.degree;
    int* xCoeffs = x.coef;
    int* yCoeffs = y.coef;
    // assume either degrees for equal cases, 
    // otherwise use one of them
    int highest = xDeg;
    if (xDeg < yDeg) {
        highest = yDeg;
    }
    else {
        highest = xDeg;
    }
    // iterate all and subtract entries
    int* newCoeffs = new int[highest];
    for (int i = 0; i < highest; i++) {
        // assume values are zero if exceeds degree term
        int intX = 0;
        if (i < xDeg) {
            intX = xCoeffs[i];
        }
        int intY = 0;
        if (i < yDeg) {
            intY = yCoeffs[i];
        };
        newCoeffs[i] = intX - intY;
    }
    return Polynomial(newCoeffs, highest);
}

ostream& operator << (ostream& os, const Polynomial& poly) {
    for (int polyDeg = poly.degree - 1; polyDeg > -1; polyDeg--) {
        int polyCoef = (poly.coef)[polyDeg];
        if (polyCoef != 0) {
            os << polyCoef << "x^" << polyDeg;

            // Print add sign until last polynomial
            if (polyDeg - 1 > -1) {
                os << " + ";
            }
        }
    }
    os << endl;
    return os;
}
