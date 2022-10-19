// 10380722, Anthony, Chen
// Date: 10/16/2022
// Lab12, Problem1
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
    int polyA_Deg = 5;
    int* polyA_Coeff = new int[polyA_Deg + 1];
    polyA_Coeff[0] = 1;
    polyA_Coeff[1] = 5;
    polyA_Coeff[2] = 3;
    polyA_Coeff[3] = 8;
    polyA_Coeff[4] = 4;
    polyA_Coeff[5] = 7;

    int polyB_Deg = 7;
    int* polyB_Coeff = new int[polyB_Deg + 1];
    polyB_Coeff[0] = 2;
    polyB_Coeff[1] = 1;
    polyB_Coeff[2] = 4;
    polyB_Coeff[3] = 5;
    polyB_Coeff[4] = 8;
    polyB_Coeff[5] = 3;
    polyB_Coeff[6] = 1;
    polyB_Coeff[7] = 2;

    Polynomial poly_A = Polynomial(polyA_Coeff, polyA_Deg + 1);
    Polynomial poly_B = Polynomial(polyB_Coeff, polyB_Deg + 1);

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