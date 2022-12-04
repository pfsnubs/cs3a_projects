#include "point.h"
using namespace std;

template <class T, class V>
point<T,V>::point(T x, V y) {
    x_coord = x;
    y_coord = y;
}

template <class T, class V>
void point<T, V>::setPoint(T x, V y) {
    x_coord = x;
    y_coord = y;
}

template <class T, class V>
T point<T, V>::getXCoord() const {
    return x_coord;
}

template <class T, class V>
V point<T, V>::getYCoord() const {
    return y_coord;
}