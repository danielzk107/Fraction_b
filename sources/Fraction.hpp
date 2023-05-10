namespace ariel
{
    class Fraction;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
using namespace ariel;

class ariel::Fraction
{
public:
    int num, denom; // Numerator and denominator

    Fraction(int num, int denom);
    Fraction(float fr);
    Fraction();
    int getNumerator();
    int getDenominator();
    Fraction operator--();    // Prefix
    Fraction operator--(int); // Postfix
    Fraction operator++();    // Prefix
    Fraction operator++(int); // Postfix
    void FixGCD();
};

Fraction Float_to_Fraction(float a);

Fraction operator+(Fraction a, Fraction b);
Fraction operator+(Fraction a, float b);
Fraction operator+(float a, Fraction b);

Fraction operator-(Fraction a, Fraction b);
Fraction operator-(Fraction a, float b);
Fraction operator-(float a, Fraction b);

Fraction operator/(Fraction a, Fraction b);
Fraction operator/(Fraction a, float b);
Fraction operator/(float a, Fraction b);

Fraction operator*(Fraction a, Fraction b);
Fraction operator*(float a, Fraction b);
Fraction operator*(Fraction a, float b);

bool operator==(Fraction a, Fraction b);
bool operator==(float a, Fraction b);
bool operator==(Fraction a, float b);

bool operator!=(Fraction a, Fraction b);
bool operator!=(float a, Fraction b);
bool operator!=(Fraction a, float b);

bool operator<(Fraction a, Fraction b);
bool operator<(float a, Fraction b);
bool operator<(Fraction a, float b);

bool operator>(Fraction a, Fraction b);
bool operator>(Fraction a, float b);
bool operator>(float a, Fraction b);

bool operator>=(Fraction a, Fraction b);
bool operator>=(float a, Fraction b);
bool operator>=(Fraction a, float b);

bool operator<=(Fraction a, Fraction b);
bool operator<=(float a, Fraction b);
bool operator<=(Fraction a, float b);

ostream &operator<<(ostream &a, Fraction &b);
Fraction &operator>>(istream &a, Fraction &b);
Fraction &operator>>(Fraction &a, Fraction &b);
