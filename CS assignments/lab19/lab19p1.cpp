// 10380722, Anthony, Chen
// Date: 11/13/2022
// Lab 19, Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
private:
    string name;
    double balance;
public:
    // constructors
    Account() {};
    Account(string name, double balance) {
        this->name = name;
        this->balance = balance;
    }

    // mutator methods
    void setName(string name) {
        this->name = name;
    }
    void setBalance(double balance) {
        this->balance = balance;
    }

    // accessor methods
    string getName() {
        return name;
    }
    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double amount;
public:
    // constructors
    SavingsAccount() {};
    SavingsAccount(string name, double balance, double interestRate) 
        : Account(name, balance) {
        this->interestRate = interestRate;
        this->amount = balance + (balance * interestRate);
    }

    // mutator methods
    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }
    void setAmount(double amount) {
        this->amount = amount;
    }

    // accessor methods
    double getInterestRate() {
        return interestRate;
    }
    double getAmount() {
        return amount;
    }
};

int main()
{
    int totalCustomers = 0;
    ifstream infile;
    string fileName = "lab19\\customer.txt";
    infile.open(fileName);
    if (infile.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    // count number of entries to make for each array
    string line;
    while (!infile.eof()) {
        getline(infile, line);
        totalCustomers++;
    }

    // create array of pointers with count entries
    SavingsAccount* accounts = new SavingsAccount[totalCustomers];

    // re-read file again and assign vars 
    infile.clear(); // restart file reading 
    infile.seekg(0); // start back at first line
    int iter = 0;
    while (!infile.eof()) {
        double balance, interest;
        string name;
        infile >> name >> balance >> interest;
        accounts[iter] = SavingsAccount(name, balance, interest);
        iter++;
    }

    // arrange customers by their amount in descending order
    for (int i = 0; i < totalCustomers - 1; i++) {
        if (accounts[i].getAmount() < accounts[i + 1].getAmount()) {
            SavingsAccount temp = accounts[i];
            accounts[i] = accounts[i + 1];
            accounts[i + 1] = temp;
            // reset loop to check again
            i = -1;
        }
    }

    // print customers list
    cout << setw(10) << "name" << setw(10) << "balance" 
        << setw(10) << "interest" << setw(10) << "amount" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < totalCustomers; i++) {
        SavingsAccount acc = accounts[i];
        cout << setw(10) << acc.getName() << setw(10) 
            << setprecision(6) << acc.getBalance()
            << setw(10) 
            << setprecision(3) << acc.getInterestRate() 
            << setw(10) 
            << setprecision(6) << acc.getAmount() << endl;
    }
    return 0;
}