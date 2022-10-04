// 10380722, Anthony, Chen
// Date: 9/18/2022
// Lab6, Problem1

#include <string>
#include <iostream>

using namespace std;


class student {
private:
    int id;
    string name;
    double gpa;
public:
    student();
    student(int id);
    student(int id, string name);
    student(int id, string name, double gpa);

    int getId();
    string getName();
    double getGpa();
};

student::student() : id(0), name("none"), gpa(0.0) {

};

student::student(int id) : id(id), name("none"), gpa(0.0) {

};

student::student(int id, string name) : id(id), name(name), gpa(0.0) {

};

student::student(int id, string name, double gpa) : id(id), name(name), gpa(gpa) {

};

int student::getId() {
    return id;
}

string student::getName() {
    return name;
}

double student::getGpa() {
    return gpa;
}



// four function declarations
int maind()
{
    student s1 = {420, "bruh", 6.90};
    cout << s1.getId() << " " << s1.getName() << " " << s1.getGpa();
    return 0;
}
