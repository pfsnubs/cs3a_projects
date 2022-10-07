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