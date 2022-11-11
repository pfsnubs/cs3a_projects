#include "Node.h"

ostream& operator << (ostream& os, NodePtr head) {
    for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link) {
        os << ptr->data << "->";
    }

    // declare NULL at end because ends will always point to null
    os << "NULL";
    os << endl;
    return os;
}
