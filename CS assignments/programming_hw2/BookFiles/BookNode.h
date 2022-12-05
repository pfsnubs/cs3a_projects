#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Book.h"

// namespaces & typedefs
using namespace std;
typedef struct BookNode* BookNodePtr;

struct BookNode
{
public:
	Book* data = NULL;
    BookNodePtr link = NULL;
    BookNode() {};

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