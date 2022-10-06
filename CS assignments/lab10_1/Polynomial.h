// Polynomial header file
#include<iostream>
using namespace std;

class Polynomial
{
public:
	Polynomial();
	Polynomial(int d);
	Polynomial(int* c, int d);
	int getDegree();
	int* getCoef();
	friend Polynomial add(Polynomial x, Polynomial y);
	friend Polynomial subtract(Polynomial x, Polynomial y);
	friend Polynomial multiply(Polynomial x, Polynomial y);
	friend Polynomial polySetup(string fileName);
	void print();

private:
	int* coef;
	int degree;
};