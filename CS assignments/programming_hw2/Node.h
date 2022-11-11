#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

// namespaces & typedefs
typedef struct node<class T>* NodePtr;
using namespace std;

// node structure
template <class T> struct node
{
public:
    T data;
    NodePtr link;
    friend ostream& operator << (ostream& os, const node&);
};

