#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class person {
private:
    string name;
    int age;
public:
    person(): name(" "), age(0){}
    person(string n, int a) : name(n), age(a){}
    friend istream& operator >>(istream& is, person& p);
    friend ostream& operator <<(ostream& os, const person& p);
    person& operator++();
};

person& person::operator++() {
    age++;
    return *this;
}

istream& operator>>(istream& is, person& p)
{
    is >> p.name >> p.age;
    return is;
}

ostream& operator<<(ostream& os, const person& p)
{
    cout << "You are " << p.name << " and " << p.age << " years old.";
    return os;
}


int main()
{
    person ps;
    // read data into ps
    cin >> ps;
    // print data from ps
    ++ps;
    cout << ps;


    return 0;
}
