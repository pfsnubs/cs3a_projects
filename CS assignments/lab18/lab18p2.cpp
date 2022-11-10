// 10380722, Anthony, Chen
// Date: 11/13/2022
// Lab 18, Problem 2

#include <iostream>
#include <fstream>
using namespace std;

class Person {
private:
    string name;
public:
    // constructors
    Person() {};
    Person(string name) {
        this->name = name;
    }

    // mutators
    void setName(string name) {
        this->name = name;
    }

    // accessors
    string getName() {
        return name;
    }

    void print() {
        cout << "This person's name is " << name << endl;
    }
};

class Vehicle {
private:
    string manufacturer;
    int totalCylinders;
    Person owner;
public:
    // constructors
    Vehicle() {};
    Vehicle(string manufacturer, int totalCylinders, Person owner) {
        this->manufacturer = manufacturer;
        this->totalCylinders = totalCylinders;
        this->owner = owner;
    }

    // mutators
    void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }
    void setCylinders(int totalCylinders) {
        this->totalCylinders = totalCylinders;
    }
    void setOwner(Person owner) {
        this->owner = owner;
    }

    // accessors
    string getManufacturer() {
        return manufacturer;
    }
    int getCylinders() {
        return totalCylinders;
    }
    Person getOwner() {
        return owner;
    }

    void print() {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Cylinders: " << totalCylinders << endl;
        cout << "Owner: " << owner.getName() << endl;
    }
};

class Truck : public Vehicle {
private:
    int loadCapacity;
public:
    Truck() {};
    Truck(string manufacturer, int totalCylinders, Person owner, int loadCapacity) 
        : Vehicle(manufacturer, totalCylinders, owner) {
        this->loadCapacity = loadCapacity;
    }

    // mutators
    void setCapacity(int loadCapacity) {
        this->loadCapacity = loadCapacity;
    }

    // accessors
    int getCapacity() {
        return loadCapacity;
    }

    void print() {
        cout << "Load capacity of " << Vehicle::getManufacturer() << ": " << loadCapacity << " lbs" << endl;
    }
};

int main()
{
    Person bob("Bob");
    Person bill("Bill");
    Vehicle randoCar("Subaru", 6, bob);
    Truck randoTruck("Honda", 8, bill, 100);

    bob.print();
    randoCar.print();
    cout << endl;
    bill.print();
    randoTruck.print();
    return 0;
}