// 10380722, Anthony, Chen
// Date: 10/9/2022
// Lab10, Problem1

#include<iostream>
#include<cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

#include "Polynomial.h"

using namespace std;

// prototypes
Polynomial polySetup();

// functions
Polynomial polySetup(string fileName) {
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
    Polynomial poly = Polynomial(coeffList, totalDegree);
    return poly;
}

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
    for (int i = 0; i < maxDegree; i++) {
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
            newCoeffs[combinedDegrees] = newCoeffs[combinedDegrees] + newMult;
        }
    }
    return Polynomial(newCoeffs, maxDegree);
};

int main()
{
    Polynomial poly_A = polySetup("A.txt");
    Polynomial poly_B = polySetup("B.txt");

    cout << "< Polynomial A >" << endl;
    poly_A.print();
    cout << endl;

    cout << "< Polynomial B >" << endl;
    poly_B.print();
    cout << endl;


    Polynomial addPoly = add(poly_A, poly_B);
    cout << "< Polynomial A + B >" << endl;
    addPoly.print();
    cout << endl;

    Polynomial subPoly = subtract(poly_A, poly_B);
    cout << "< Polynomial A - B >" << endl;
    subPoly.print();
    cout << endl;

    Polynomial multiPoly = multiply(poly_A, poly_B);
    cout << "< Polynomial A * B >" << endl;
    multiPoly.print();
    cout << endl;

    return 0;
}
