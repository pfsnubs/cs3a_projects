#include <iostream>

using namespace std;

template <class T, class V>
class point {
public:
    point(T x, V y) {
        x_coord = x;
        y_coord = y;
    }

    void setPoint(T x, V y) {
        x_coord = x;
        y_coord = y;
    }

    T getXCoord() const {
        return x_coord;
    }

    V getYCoord() const {
        return y_coord;
    }

private:
    T x_coord;
    V y_coord;
};

int mains()
{
    point <int, char> p(5, 'A');
    cout << "p.x: " << p.getXCoord() << " p.y: " << p.getYCoord();

    return 0;
}