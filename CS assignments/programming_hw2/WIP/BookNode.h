#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

// namespaces & typedefs
using namespace std;

// node structure
template <class T> struct Node {
public:
    Node* link;
    T* data;
    Node() {};
    Node(Node* link, T* data) {

    }
    friend ostream& operator << (ostream& os, const Node& head) {
        for (Node* ptr = head; ptr != NULL; ptr = ptr->link) {
            os << ptr->data << "->";
        };

        // declare NULL at end because ends will always point to null
        os << "NULL";
        os << endl;
        return os;
    }
};
