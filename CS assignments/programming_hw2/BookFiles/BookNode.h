#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Book.h"

// Constants
using namespace std;
typedef struct BookNode* BookNodePtr;

struct BookNode
{
public:
	Book* data = NULL;          // Book pointer used to handle different book types
    BookNodePtr link = NULL;    // link used to point to proceeding BookNode

    // Constructor
    BookNode() {};

    // Functions
    friend ostream& operator << (ostream& os, const BookNodePtr& head) {
        for (BookNodePtr ptr = head; ptr != NULL; ptr = ptr->link) {
            os << *ptr->data << "->";
        };

        // declare NULL at end because ends will always point to null
        os << "NULL";
        os << endl;
        return os;
    }
};