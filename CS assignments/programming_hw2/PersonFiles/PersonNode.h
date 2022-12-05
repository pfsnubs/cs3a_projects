#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Person.h"

// namespaces & typedefs
using namespace std;
typedef struct PersonNode* PersonNodePtr;

struct PersonNode
{
public:
    Person* data = NULL; // needs to be pointer to use polymorphism (ok to keep, do same w/ book)
    PersonNodePtr link = NULL;
    PersonNode() {};

    friend ostream& operator << (ostream& os, const PersonNodePtr& head) {
        for (PersonNodePtr ptr = head; ptr != NULL; ptr = ptr->link) {
            os << *ptr->data << "->";
        };

        // declare NULL at end because ends will always point to null
        os << "NULL";
        os << endl;
        return os;
    }
};
