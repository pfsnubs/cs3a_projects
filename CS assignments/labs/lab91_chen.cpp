// 10380722, Anthony, Chen
// Date: 10/9/2022
// Lab9, Problem1

#include<iostream>
#include<cstdlib>
#include <iomanip>

using namespace std;

// constants
const double QUARTER_VAL = 0.25;
const double DIME_VAL = 0.10;
const double NICKEL_VAL = 0.05;
const double CENT_VAL = 0.01;


// classes
class Wallet
{
private:
	int quarters; // number of quarters 
	int dimes;     // number of dimes 
	int nickels; // number of nickels 
	int cents; // number of cents 
public:
	// complete the class with constructors and member functions
	Wallet();
	Wallet(int newQ, int newD, int newN, int newC);
	int getQuarters();
	int getDimes();
	int getNickels();
	int getCents();
	void setQuarters(int val);
	void setDimes(int val);
	void setNickels(int val);
	void setCents(int val);
	double calculateAmount();
	Wallet add(Wallet x, Wallet y);
};

// Wallet constructor
Wallet::Wallet(){};

Wallet::Wallet(int newQ, int newD, int newN, int newC) {
	quarters = newQ;
	dimes = newD;
	nickels = newN;
	cents = newC;
};

// Wallet functions
int Wallet::getQuarters() {
	return quarters;
};
int Wallet::getDimes() {
	return dimes;
};
int Wallet::getNickels() {
	return nickels;
};
int Wallet::getCents() {
	return cents;
};

void Wallet::setQuarters(int val) {
	quarters = val;
};
void Wallet::setDimes(int val) {
	dimes = val;
};
void Wallet::setNickels(int val) {
	nickels = val;
};
void Wallet::setCents(int val) {
	cents = val;
};

double Wallet::calculateAmount() {
	return (QUARTER_VAL * getQuarters()) + (DIME_VAL * getDimes())
		+ (NICKEL_VAL * getNickels()) + (CENT_VAL * getCents());
};

Wallet Wallet::add(Wallet x, Wallet y)
{
	int q, d, n, c;
	q = x.getQuarters() + y.getQuarters();
	d = x.getDimes() + y.getDimes();
	n = x.getNickels() + y.getNickels();
	c = x.getCents() + y.getCents();
	Wallet newWallet = Wallet(q, d, n, c);
	return newWallet;
}

int main()
{
	int totalWallets = 2;
	Wallet* walletArr = new Wallet[totalWallets];
	for (int i = 0; i < totalWallets; i++) {
		int quarterVal, dimeVal, nickelVal, centVal;
		int displayVal = i + 1;
		cout << setw(10) << "Enter the number of quarters for w" << displayVal << " : ";
		cin >> quarterVal;
		cout << setw(10) << "Enter the number of dimes for w" << displayVal << " : ";
		cin >> dimeVal;
		cout << setw(10) << "Enter the number of nickels for w" << displayVal << " : ";
		cin >> nickelVal;
		cout << setw(10) << "Enter the number of pennies for w" << displayVal << " : ";
		cin >> centVal;
		cout << endl;
		walletArr[i] = Wallet(quarterVal, dimeVal, nickelVal, centVal);
	}
	cout << endl;

	// print out wallet values
	for (int i = 0; i < totalWallets; i++) {
		Wallet walletEntry = walletArr[i];
		cout << "W" << i << ": " << endl;
		cout << "\t" << walletEntry.getQuarters() << " quarters" << endl;
		cout << "\t" << walletEntry.getDimes() << " dimes" << endl;
		cout << "\t" << walletEntry.getNickels() << " nickels" << endl;
		cout << "\t" << walletEntry.getCents() << " cents" << endl;
		cout << "\t----> amount = $" << walletEntry.calculateAmount() << endl;
		cout << endl;
	}

	// compare wallet balances
	Wallet walletOne = walletArr[0];
	Wallet walletTwo = walletArr[1];
	if (walletOne.calculateAmount() > walletTwo.calculateAmount()) {
		cout << "w1 amount is greater than w2" << endl;
	}
	else if(walletOne.calculateAmount() < walletTwo.calculateAmount()) {
		cout << "w2 amount is greater than w1" << endl;
	}
	else {
		cout << "both wallets have the same amount" << endl;
	}

	cout << endl;
	cout << "Create new Wallet w3 by adding w1 and w2" << endl;
	cout << endl;

	// create w3 by adding both wallet's change together
	Wallet walletThree = walletThree.add(walletOne, walletTwo);

	cout << "W3: " << endl;
	cout << "\t" << walletThree.getQuarters() << " quarters" << endl;
	cout << "\t" << walletThree.getDimes() << " dimes" << endl;
	cout << "\t" << walletThree.getNickels() << " nickels" << endl;
	cout << "\t" << walletThree.getCents() << " cents" << endl;
	cout << "\t----> amount = $" << walletThree.calculateAmount() << endl;
	cout << endl;

	return 0;
}
