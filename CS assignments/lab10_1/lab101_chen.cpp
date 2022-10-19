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

int main()
{
    Polynomial poly_A("A.txt");
    Polynomial poly_B("B.txt");
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