#include <iostream>
#include "point.h"
#include "point.cpp"
using namespace std;

int main()
{
    point <int, char> p(5, 'A');
    cout << "p.x: " << p.getXCoord() << " p.y: " << p.getYCoord();

    return 0;
}