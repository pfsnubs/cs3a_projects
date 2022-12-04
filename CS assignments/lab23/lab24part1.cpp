// 10380722, Anthony, Chen
// Date: 12/4/2022
// Lab 24 Part 1

#include <iostream>
#include "Set.cpp"
using namespace std;


int main()
{
    Set<int> s1;
    Set<char>s2(20);
    s1.insert(5);
    s1.insert(6);
    s1.insert(7);
    s1.insert(5);
    s1.insert(8);
    s1.print();

    s1.remove(6);
    s1.print();


    s2.insert(65);
    s2.insert(68);
    s2.insert(69);
    s2.print();

    
    Set<double> s3(5);
    s3.insert(12.35312);
    s3.insert(210312031.21213);
    s3.insert(10.2304);
    s3.print();
    return 0;
}
