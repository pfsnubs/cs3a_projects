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

Polynomial::Polynomial(string fileName) {
    ifstream infile;
    infile.open(fileName);
    if (infile.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    // initialize polynomial
    int zero = 0;
    int totalDegree;
    infile >> totalDegree;
    // add TotalDegree + 1 because of constant polynomial 
    //totalDegree++;
    int* coeffList = new int[totalDegree];
    for (int i = 0; i < totalDegree; i++) {
        coeffList[i] = 0;
    }
    // read polynomial file A and assign coefficients
    while (!infile.eof()) {
        // skip line
        int coefficient, deg;
        infile >> coefficient >> deg;
        coeffList[deg] = coefficient;
        //cout << "FILE_C " << coefficient << " FILE_D " << deg << endl;
    }
    coef = coeffList;
    degree = totalDegree;
}

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

// friend functions
Polynomial add(Polynomial x, Polynomial y) {
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
    for (int i = 0; i <= highest; i++) {
        // assume values are zero if exceeds degree term
        int intX = 0;
        if (i <= xDeg) {
            intX = xCoeffs[i];
        }
        int intY = 0;
        if (i <= yDeg) {
            intY = yCoeffs[i];
        };
        newCoeffs[i] = intX + intY;
    }
    return Polynomial(newCoeffs, highest);
};
Polynomial subtract(Polynomial x, Polynomial y) {
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
    for (int i = 0; i <= highest; i++) {
        // assume values are zero if exceeds degree term
        int intX = 0;
        if (i <= xDeg) {
            intX = xCoeffs[i];
        }
        int intY = 0;
        if (i <= yDeg) {
            intY = yCoeffs[i];
        };
        newCoeffs[i] = intX - intY;
    }
    return Polynomial(newCoeffs, highest);
};
Polynomial multiply(Polynomial x, Polynomial y) {
    int xDeg = x.degree;
    int yDeg = y.degree;
    int* xCoeffs = x.coef;
    int* yCoeffs = y.coef;
    // polynomial multiplication adds highest exponent degree
    int maxDegree = xDeg + yDeg;
    // iterate all and subtract entries
    // (include lowest in loop as well since it won't add the size + 1)
    int* newCoeffs = new int[maxDegree];

    // initialize newCoeffs with all zeroes to prevent access errors
    for (int i = 0; i <= maxDegree; i++) {
        newCoeffs[i] = 0;
    }
    // distribute x polynomial coeffs into y's
    // FOIL basically multiplies entries onto another loop entry
    for (int i = 0; i <= xDeg; i++) {
        for (int j = 0; j <= yDeg; j++) {
            int newMult = xCoeffs[i] * yCoeffs[j];
            int combinedDegrees = i + j;
            // use additive setting b/c FOIL 
            // makes remaining other coeffs of different degrees
            //cout << "degree " << combinedDegrees << " mult " << newMult << endl;
            newCoeffs[combinedDegrees] = newCoeffs[combinedDegrees] + newMult;
        }
    }
    return Polynomial(newCoeffs, maxDegree);
};