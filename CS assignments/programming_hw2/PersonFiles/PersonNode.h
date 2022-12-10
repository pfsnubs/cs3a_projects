#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Person.h"

// Constants
using namespace std;
typedef struct PersonNode* PersonNodePtr;

struct PersonNode
{
public:
    Person* data = NULL;        // Person pointer used for polymorphism as well
    PersonNodePtr link = NULL;  // Link to proceeding PersonNode

    // Constructors
    PersonNode() {};        

    // Functions
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
