// Polynomial header file
#include<iostream>
#include<cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Polynomial
{
public:
	Polynomial();
	Polynomial(int d);
	Polynomial(int* c, int d);
	Polynomial(string fileName);
	int getDegree();
	int* getCoef();
	friend Polynomial add(Polynomial x, Polynomial y);
	friend Polynomial subtract(Polynomial x, Polynomial y);
	friend Polynomial multiply(Polynomial x, Polynomial y);
	void print();

private:
	int* coef;
	int degree;
};