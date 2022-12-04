#include <iostream>
#include "GenericList.h"
using namespace std;
int main()
{
    GenericList<int> firstList(2);
    firstList.add(10);
    firstList.add(20);
    cout << "firstList = " << endl;
    cout << firstList << endl;
    GenericList<char> secondList(5);
    secondList.add('A');
    secondList.add('B');
    secondList.add('C');
    cout << "secondList = " << endl;
    cout << secondList << endl;
    return 0;
}