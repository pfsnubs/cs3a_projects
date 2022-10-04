// 10380722, Anthony, Chen
// Date: 9/11/2022
// Lab4, Problem2

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// prototypes
void operateNums(int int1, int int2, int* add, int* sub, int* mu, int* div, int* rem);

// functions
void operateNums(int int1, int int2, int* add, int* sub, int* mu, int* div, int* rem) {
    // operate equations onto int1 and int2
    // set values of int values
    *add = int1 + int2;
    *sub = int1 - int2;
    *mu = int1 * int2;
    *div = int1 / int2;
    *rem = int1 % int2;
}

int main()
{
    // create int and pointer int of operations
    int int1, int2;
    int *add, *sub, *mu, *div, *rem;

    // create a new int heap address for each variable object
    // ** must be initialized in same thread, cannot be placed in other functions
    add = new int;
    sub = new int;
    mu = new int;
    div = new int;
    rem = new int;

    // ask for user input
    cout << "Enter two integers : ";
    cin >> int1 >> int2;
    cout << endl;

    // rewrite over all operation variables
    operateNums(int1, int2, add, sub, mu, div, rem);

    // print operations 
    cout << int1 << " + " << int2 << " : " << *add << endl;
    cout << int1 << " - " << int2 << " : " << *sub << endl;
    cout << int1 << " * " << int2 << " : " << *mu << endl;
    cout << int1 << " / " << int2 << " : " << *div << endl;
    cout << int1 << " % " << int2 << " : " << *rem << endl;

    cout << endl;
    cout << "-----------------------------------------" << endl;

    return 0;
}