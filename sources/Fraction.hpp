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
    bool operator==(const Fraction &fraction) const;
    bool operator!=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
};

bool operator==(float a, const Fraction &b);
bool operator==(const Fraction &a, float b);

bool operator!=(float a, const Fraction &b);
bool operator!=(const Fraction &a, float b);

bool operator<(float a, const Fraction &b);
bool operator<(const Fraction &a, float b);

bool operator>(const Fraction &a, float b);
bool operator>(float a, const Fraction &b);

bool operator>=(float a, const Fraction &b);
bool operator>=(const Fraction &a, float b);

bool operator<=(float a, const Fraction &b);
bool operator<=(const Fraction &a, float b);

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

ostream &operator<<(ostream &a, Fraction &b);
Fraction &operator>>(istream &a, Fraction &b);
Fraction &operator>>(Fraction &a, Fraction &b);
