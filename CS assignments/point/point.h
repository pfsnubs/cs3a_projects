#pragma once
using namespace std;

template <class T, class V>
class point {
public:
    point(T x, V y);
    void setPoint(T x, V y);
    T getXCoord() const;
    V getYCoord() const;
private:
    T x_coord;
    V y_coord;
};
