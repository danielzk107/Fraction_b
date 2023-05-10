#include "Fraction.hpp"
#include <numeric>
#include <cmath>
#include <iomanip>
#include <string>
using namespace ariel;

Fraction::Fraction(int a, int b)
{
    if (b == 0)
    {
        throw(b);
    }
    num = a;
    denom = b;
    FixGCD();
}
Fraction::Fraction(float fr)
{
    float fr_3dec = roundf(fr * 1000) / 1000;
    Fraction f = Float_to_Fraction(fr_3dec);
    num = f.num;
    denom = f.denom;
}

Fraction::Fraction()
{
    num = 1;
    denom = 1;
}

int Fraction::getNumerator()
{
    return num;
}

int Fraction::getDenominator()
{
    return denom;
}

Fraction Fraction::operator--()
{
    num -= denom;
    FixGCD();
    return *this;
} // Prefix
Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    num -= denom;
    FixGCD();
    return temp;
} // Postfix
Fraction Fraction::operator++()
{
    num += denom;
    FixGCD();
    return *this;
} // Prefix
Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    num += denom;
    FixGCD();
    return temp;
} // Postfix

void Fraction::FixGCD()
{
    int gcd = std::gcd(num, denom);
    if (gcd < 1)
    {
        return;
    }
    num = num / gcd;
    denom = denom / gcd;
}



Fraction Float_to_Fraction(float a)
{
    int integralpart = static_cast<int>(a);             // Casting the number to int, disregarding the fractional part.
    int p = 1000000;                                    // Arbitrarily large number - the larger the number, the more accurate the function would be
    float fractionalpart = std::fabs(a - integralpart); // Getting the fractional part in order to compare it to num/denom
    int num = round(fractionalpart * p) / std::gcd(int(round(fractionalpart * p)), p);
    int denom = p / std::gcd(int(round(fractionalpart * p)), p);
    Fraction output(num, denom);
    output.FixGCD();
    return output;
}

Fraction operator+(Fraction a, Fraction b)
{
    int new_num = a.num * b.denom + b.num * a.denom;
    int new_denom = a.denom * b.denom;
    Fraction output(new_num, new_denom);
    return output;
};
Fraction operator+(Fraction a, float b)
{
    float b_3dec = roundf(b * 1000) / 1000;
    Fraction fb = Float_to_Fraction(b_3dec);
    Fraction output = a + fb;
    return output;
};
Fraction operator+(float a, Fraction b)
{
    float a_3dec = roundf(a * 1000) / 1000;
    Fraction fa = Float_to_Fraction(a_3dec);
    Fraction output = fa + b;
    return output;
}

Fraction operator-(Fraction a, Fraction b)
{
    int new_num = a.num * b.denom - b.num * a.denom;
    int new_denom = a.denom * b.denom;
    Fraction output(new_num, new_denom);
    return output;
};
Fraction operator-(Fraction a, float b)
{
    float b_3dec = roundf(b * 1000) / 1000;
    Fraction fb = Float_to_Fraction(b_3dec);
    return a - fb;
};
Fraction operator-(float a, Fraction b)
{
    float a_3dec = roundf(a * 1000) / 1000;
    Fraction fa = Float_to_Fraction(a_3dec);
    return fa - b;
}

Fraction operator/(Fraction a, Fraction b)
{
    int new_num = a.num * b.denom;
    int new_denom = b.num * a.denom;
    Fraction output(new_num, new_denom);
    return output;
};
Fraction operator/(Fraction a, float b)
{
    if (b == 0)
    {
        throw(b);
    }
    float b_3dec = roundf(b * 1000) / 1000;
    Fraction fb = Float_to_Fraction(b_3dec);
    return a / fb;
};
Fraction operator/(float a, Fraction b)
{
    float a_3dec = roundf(a * 1000) / 1000;
    Fraction fa = Float_to_Fraction(a_3dec);
    return fa / b;
}

Fraction operator*(Fraction a, Fraction b)
{
    int new_num = a.num * b.num;
    int new_denom = a.denom * b.denom;
    Fraction output(new_num, new_denom);
    return output;
};
Fraction operator*(float a, Fraction b)
{
    float a_3dec = roundf(a * 1000) / 1000;
    Fraction fa = Float_to_Fraction(a_3dec);
    return fa * b;
};
Fraction operator*(Fraction a, float b)
{
    float b_3dec = roundf(b * 1000) / 1000;
    Fraction fb = Float_to_Fraction(b_3dec);
    return a * fb;
}

// We could compare nums and denoms but to keep all equality checks consistant, we will convert to floats.
bool Fraction::operator==(const Fraction& other) const
{
    float a_3dec = roundf(float(num) / denom * 1000) / 1000;
    float b_3dec = roundf(float(other.num) / other.denom * 1000) / 1000;
    if (a_3dec == b_3dec)
    {
        return true;
    }
    return false;
};

bool operator==(float a, const Fraction &b)
{
    float b_3dec = roundf(float(b.num) / b.denom * 1000) / 1000;
    float a_3dec = roundf(a * 1000) / 1000;
    if (a_3dec == b_3dec)
    {
        return true;
    }
    return false;
}
bool operator==(const Fraction &a, float b){
    float a_3dec = roundf(float(a.num) / a.denom * 1000) / 1000;
    float b_3dec = roundf(b * 1000) / 1000;
    if (a_3dec == b_3dec)
    {
        return true;
    }
    return false;
}


bool Fraction::operator!=(const Fraction& other) const
{
    float a_3dec = roundf(float(num) / denom * 1000) / 1000;
    float b_3dec = roundf(float(other.num) / other.denom * 1000) / 1000;
    if (a_3dec != b_3dec)
    {
        return true;
    }
    return false;
};

bool operator!=(float a, const Fraction &b)
{
     float b_3dec = roundf(float(b.num) / b.denom * 1000) / 1000;
    float a_3dec = roundf(a * 1000) / 1000;
    if (a_3dec != b_3dec)
    {
        return true;
    }
    return false;
}
bool operator!=(const Fraction &a, float b){
    float a_3dec = roundf(float(a.num) / a.denom * 1000) / 1000;
    float b_3dec = roundf(b * 1000) / 1000;
    if (a_3dec != b_3dec)
    {
        return true;
    }
    return false;
}

bool Fraction::operator<(const Fraction& other) const
{
    float a_3dec = roundf(float(num) / denom * 1000) / 1000;
    float b_3dec = roundf(float(other.num) / other.denom * 1000) / 1000;
    if (a_3dec < b_3dec)
    {
        return true;
    }
    return false;
};

bool operator<(float a, const Fraction &b)
{
     float b_3dec = roundf(float(b.num) / b.denom * 1000) / 1000;
    float a_3dec = roundf(a * 1000) / 1000;
    if (a_3dec != b_3dec)
    {
        return true;
    }
    return false;
}
bool operator<(const Fraction &a, float b){
    float a_3dec = roundf(float(a.num) / a.denom * 1000) / 1000;
    float b_3dec = roundf(b * 1000) / 1000;
    if (a_3dec < b_3dec)
    {
        return true;
    }
    return false;
}

bool Fraction::operator>(const Fraction& other) const
{
    float a_3dec = roundf(float(num) / denom * 1000) / 1000;
    float b_3dec = roundf(float(other.num) / other.denom * 1000) / 1000;
    if (a_3dec > b_3dec)
    {
        return true;
    }
    return false;
};

bool operator>(float a, const Fraction &b)
{
     float b_3dec = roundf(float(b.num) / b.denom * 1000) / 1000;
    float a_3dec = roundf(a * 1000) / 1000;
    if (a_3dec > b_3dec)
    {
        return true;
    }
    return false;
}
bool operator>(const Fraction &a, float b){
    float a_3dec = roundf(float(a.num) / a.denom * 1000) / 1000;
    float b_3dec = roundf(b * 1000) / 1000;
    if (a_3dec > b_3dec)
    {
        return true;
    }
    return false;
}


bool Fraction::operator>=(const Fraction& other) const
{
    float a_3dec = roundf(float(num) / denom * 1000) / 1000;
    float b_3dec = roundf(float(other.num) / other.denom * 1000) / 1000;
    if (a_3dec >= b_3dec)
    {
        return true;
    }
    return false;
};

bool operator>=(float a, const Fraction &b)
{
     float b_3dec = roundf(float(b.num) / b.denom * 1000) / 1000;
    float a_3dec = roundf(a * 1000) / 1000;
    if (a_3dec >= b_3dec)
    {
        return true;
    }
    return false;
}
bool operator>=(const Fraction &a, float b){
    float a_3dec = roundf(float(a.num) / a.denom * 1000) / 1000;
    float b_3dec = roundf(b * 1000) / 1000;
    if (a_3dec >= b_3dec)
    {
        return true;
    }
    return false;
}

bool Fraction::operator<=(const Fraction& other) const
{
    float a_3dec = roundf(float(num) / denom * 1000) / 1000;
    float b_3dec = roundf(float(other.num) / other.denom * 1000) / 1000;
    if (a_3dec <= b_3dec)
    {
        return true;
    }
    return false;
};

bool operator<=(float a, const Fraction &b)
{
     float b_3dec = roundf(float(b.num) / b.denom * 1000) / 1000;
    float a_3dec = roundf(a * 1000) / 1000;
    if (a_3dec <= b_3dec)
    {
        return true;
    }
    return false;
}
bool operator<=(const Fraction &a, float b){
    float a_3dec = roundf(float(a.num) / a.denom * 1000) / 1000;
    float b_3dec = roundf(b * 1000) / 1000;
    if (a_3dec <= b_3dec)
    {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &a, Fraction &b)
{
    a << b.num << "/" << b.denom;
    return a;
}
Fraction &operator>>(istream &a, Fraction &b)
{
    string val;
    val.append((std::istreambuf_iterator<char>(a)),
               std::istreambuf_iterator<char>());
    if (val.length() < 3)
    {
        printf("Throwing in line 301\n");
        throw(&a);
    }
    int num_mult = 1, denom_mult = 0; // multipliers of 10
    size_t index = 1;
    // Get num
    if (std::isdigit(val.at(0))) // num is positive
    {
        b.num = int(val.at(0) - '0');
        while (index < val.length() && std::isdigit(val.at(index)))
        {
            b.num = b.num * num_mult + int(val.at(index) - '0');
            index++;
            num_mult++;
        }
    }
    else if (val.at(0) == '-') // num is negative
    {
        int temp_num;
        index++;
        if (std::isdigit(val.at(1)))
        {
            temp_num = int(val.at(1) - '0');
            while (index < val.length() && std::isdigit(val.at(index)))
            {
                temp_num = temp_num * num_mult + int(val.at(index) - '0');
                index++;
                num_mult++;
            }
        }
        else
        {
            printf("Throwing in line 333\n");
            throw(&a);
        }
        b.num = temp_num * -1;
    }
    else
    {
        printf("Throwing in line 340\n");
        throw(&a);
    }
    // Check if seperator exists - if not, then input is ilegal
    if (index == val.length() || (val.at(index) != ',' && val.at(index) != '/' && val.at(index) != ' '))
    {
        printf("Throwing in line 346\n");
        throw(&a);
    }
    index++;
    // Get denom
    if (index < val.length() && std::isdigit(val.at(index))) // Denom is positive
    {
        b.denom = 0;
        // Both the if statement and the while loop nested within it use the same condition, and this may seem ineficient.
        // However, it is important to use both the loop and the if statement in order to take care of all possible cases and catch errors in the input.
        while (index < val.length() && std::isdigit(val.at(index)))
        {
            b.denom = b.denom * denom_mult + int(val.at(index) - '0');
            index++;
            denom_mult++;
        }
    }
    else if (index < val.length() && val.at(index) == '-') // Denom is negative
    {
        int temp_denom = 0;
        index++;
        while (index < val.length() && std::isdigit(val.at(index)))
        {
            temp_denom = temp_denom * denom_mult + int(val.at(index) - '0');
            denom_mult++;
            index++;
        }
        b.denom = temp_denom * -1;
    }
    else
    {
        printf("Throwing in line 376\n");
        cout << val.at(index) << endl;
        throw(&a);
    }
    return b;
}