// 10380722, Anthony, Chen
// Date: 10/23/2022
// Homework Project 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

class HospitalEmployee {
private:
    string name;
    int number;
public:
    HospitalEmployee() {};
    HospitalEmployee(string name, int number) {
        this->name = name;
        this->number = number;
    }

    void setName(string name) {
        this->name = name;
    }
    void setNumber(int number) {
        this->number = number;
    }

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
    Doctor() {};
    Doctor(string name, int number, string specialty) : HospitalEmployee(name, number) {
        this->specialty = specialty;
    }

    void setSpecialty(string specialty) {
        this->specialty = specialty;
    }

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
    Nurse() {};
    Nurse(string name, int number, int numPat) : HospitalEmployee(name, number){
        numPatients = numPat;
    }

    void setNumPatients(int numPat) {
        this->numPatients = numPat;
    }

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