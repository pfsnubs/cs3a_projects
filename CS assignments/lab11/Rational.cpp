// Rational class cpp file
#include "Rational.h"
using namespace std;

// Rational constructors
Rational::Rational() {
    numerator = 0;
    denominator = 1;
    simplify();
};

Rational::Rational(int num) {
    numerator = num;
    denominator = 1;
    simplify();
};

Rational::Rational(int num, int den) {
    numerator = num;
    denominator = den;
    simplify();
};

// Rational fxns
void Rational::simplify() {
    // start from highest number 
    // and decrement to find lowest common denom.
    int lcd = 1;

    // stop loop it reaches the max numerator/denom
    while (lcd <= max(numerator, denominator)) {
        // typecast lcd to make sure division isnt truncated
        double numeratorLCD = numerator / (double)lcd;
        double denominatorLCD = denominator / (double)lcd;

        // check if lcd works by checking 
        // if it cleanly cuts both numbers
        //cout << lcd << " " << numeratorLCD << " " << floor(numeratorLCD) << endl;
        if (numeratorLCD == floor(numeratorLCD)
            && denominatorLCD == floor(denominatorLCD)) {
            numerator /= lcd;
            denominator /= lcd;

            // make sure to reset loop after every division so it
            // catches post-divided fractions
            lcd = 1;
        }
        lcd++;
    }
}

// friend fxns of Rational class

istream& operator>>(istream& is, Rational& a) {
    char temp;
    is >> a.numerator >> temp >> a.denominator;
    a.simplify();
    return is;
}

ostream& operator<<(ostream& os, const Rational& a) {
    return os << a.numerator << "/" << a.denominator << endl;
}

Rational operator+(const Rational& a, const Rational& b) {
    //Using (a/b + c/d = (a * d + b * c) / (b * d)) 
    Rational temp((b.numerator * a.denominator + a.numerator * b.denominator),
        (b.denominator * a.denominator));
    return temp;
}

Rational operator-(const Rational& a, const Rational& b) {
    //Using (a/b + c/d = (b * c) - (a * d) / (b * d)) 
    Rational temp((a.numerator * b.denominator - b.numerator * a.denominator),
        (b.denominator * a.denominator));
    return temp;
}

Rational operator*(const Rational& a, const Rational& b) {
    //Using (a/b * c/d = (a*c) / (b * d)) 
    Rational temp(((b.numerator * a.numerator)),
        (b.denominator * a.denominator));
    return temp;
}

Rational operator/(const Rational& a, const Rational& b) {
    //Using (a/b / c/d = (a*d) / (b*c))
    Rational temp(((b.numerator * a.denominator)),
        (b.denominator * a.numerator));
    return temp;
}

bool operator==(const Rational& a, const Rational& b) {
    return (a.numerator == b.numerator)
        && (a.denominator == b.denominator);
}

bool operator>(const Rational& a, const Rational& b) {
    return (a.numerator * b.denominator > b.numerator * a.denominator);
}

bool operator<(const Rational& a, const Rational& b) {
    return (a.numerator * b.denominator < b.numerator* a.denominator);
}

bool operator>=(const Rational& a, const Rational& b) {
    return a == b
        || a > b;
}

bool operator<=(const Rational& a, const Rational& b) {
    return a == b
        || a < b;
}