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

int main()
{
    int polyA_Deg = 5;
    int* polyA_Coeff = new int[polyA_Deg + 1];
    polyA_Coeff[0] = 1;
    polyA_Coeff[1] = 5;
    polyA_Coeff[2] = 3;
    polyA_Coeff[3] = 8;
    polyA_Coeff[4] = 4;
    polyA_Coeff[5] = 7;

    int polyB_Deg = 5;
    int* polyB_Coeff = new int[polyB_Deg + 1];
    polyB_Coeff[0] = 2;
    polyB_Coeff[1] = 1;
    polyB_Coeff[2] = 4;
    polyB_Coeff[3] = 5;
    polyB_Coeff[4] = 8;
    polyB_Coeff[5] = 3;

    Polynomial poly_A = Polynomial(polyA_Coeff, polyA_Deg + 1);
    Polynomial poly_B = Polynomial(polyB_Coeff, polyA_Deg + 1);

    cout << "< Polynomial A >" << endl;
    cout << poly_A;
    cout << endl;

    cout << "< Polynomial B >" << endl;
    cout << poly_B;
    cout << endl;

    // Demonstrating copy constructor
    Polynomial polyAdd = poly_A + poly_B;
    cout << "< Polynomial A + B >" << endl;
    cout << polyAdd;
    cout << endl;

    // Demonstrating using operator overloading "="
    Polynomial polySub;
    polySub = poly_A - poly_B;
    cout << "< Polynomial A - B >" << endl;
    cout << polySub;
    cout << endl;

    return 0;
}