// Polynomial header file
#include<iostream>
using namespace std;

class Polynomial
{
public:
	Polynomial();
	Polynomial(int d);
	Polynomial(int* c, int d);
	Polynomial(const Polynomial& poly);  // copy constructor
	~Polynomial();  // destructor

	void operator= (const Polynomial& rightSide);
	
	friend Polynomial operator+ (Polynomial x, Polynomial y);
	friend Polynomial operator- (Polynomial x, Polynomial y);
	friend ostream& operator << (ostream& os, const Polynomial&);

private:
	int* coef;
	int degree;
};