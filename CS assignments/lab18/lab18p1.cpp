// 10380722, Anthony, Chen
// Date: 11/13/2022
// Lab 18, Problem 1

#include <iostream>
#include <fstream>
using namespace std;

class HospitalEmployee {
private:
    string name;
    int number;
public:
    // constructors
    HospitalEmployee() {};
    HospitalEmployee(string name, int number) {
        this->name = name;
        this->number = number;
    }

    // mutator methods
    void setName(string name) {
        this->name = name;
    }
    void setNumber(int number) {
        this->number = number;
    }

    // accessor methods
    string getName() {
        return name;
    }
    int getNumber() {
        return number;
    }

    void work() {
        cout << name << " (" << number << ") works." << endl;
    }
};

class Doctor : public HospitalEmployee {
private:
    string specialty;
public:
    // constructors
    Doctor() {};
    Doctor(string name, int number, string specialty) : HospitalEmployee(name, number) {
        this->specialty = specialty;
    }

    // mutator methods
    void setSpecialty(string specialty) {
        this->specialty = specialty;
    }

    // accessor methods
    string getSpecialty() {
        return specialty;
    }

    void diagnose() {
        cout << HospitalEmployee::getName() << " (" << HospitalEmployee::getNumber() << ") diagnoses." << endl;
    }
};

class Nurse : public HospitalEmployee {
private:
    int numPatients;
public:
    // constructors
    Nurse() {};
    Nurse(string name, int number, int numPat) : HospitalEmployee(name, number) {
        numPatients = numPat;
    }

    // mutator methods
    void setNumPatients(int numPat) {
        this->numPatients = numPat;
    }

    // accessor methods
    int getNumPatients() {
        return numPatients;
    }

    void assist() {
        cout << HospitalEmployee::getName() << " (" << HospitalEmployee::getNumber() << ") assists." << endl;
    }
};

int main()
{
    HospitalEmployee vito("Vito", 123);
    Doctor steve("Steve", 234, "Heart");
    Nurse sonny("Sonny", 789, 6);
    cout << "   Employees information" << endl;
    cout << "----------------------------" << endl;
    vito.work();
    steve.diagnose();
    sonny.assist();
    return 0;
}