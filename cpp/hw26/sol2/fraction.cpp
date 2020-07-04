#include <iostream>
#include "fraction.hpp"

using namespace std;



Fraction::Fraction(int32_t a, uint32_t b)
{
    if (b > 0)
    {
        numerator = a;
        denominator = b;
    }
    else
        cout << "FATAL EROR!" << endl << "The denominator can`t equal 0.";
};
void Fraction::print()const
{
    cout << numerator << '/' << denominator << endl;
};
int32_t get_numerator ()const
{
    return numerator;
};
uint32_t get_denominator ()const
{
    return denominator;
};
void print_d_n()const
{
    cout << denomirator << endl << numerator << endl;
};
float Fraction::eval()const
{
    float r = 0;
    r = float(numerator)/denominator;
    return r;
};
  Fraction::Fraction reverse()const
{
    Fraction fr(get_denominator(), get_numerator());
    return fr;
};
Fraction::Fraction operator+ (const Fraction& fr)const;
{
    Fraction frac(numerator*fr.get_denominator()+denominator*fr.get_numerator(),
                  denominator*fr.get_denominator());
    return frac;
};
Fraction::Fraction operator+(int32_t n)const;
{
    Fraction fr(numerator+n*denominator, denominator);
    return fr;
};
Fraction::Fraction operator*(Fraction fr)const;
{
    Fraction frac(numerator*fr.get_numerator(), denominator*fr.get_denominator);
    return frac;
};
Fraction::Fraction operator*(int32_t n)const;
{
    Fraction fr(numerator*n, denominator);
    return fr;
};
Fraction::Fraction operator/ (Fraction fr)const;
{
    Fraction frac(numenator*fr.get_denominator(), denominator*fr.get_numenator());
    return frac;
};

Fraction::Fraction operator-()const
{
    Fraction fr(numerator*(-1), denominator);
    return fr;
};
Fraction::void operator=(const Fraction& fr)
{
    denominator = fr.get_denominator();
    numerator = fr.get_numerator();
};
Fraction::void operator+= (const Fraction& fr)
{
    numerator = numerator*fr.get_denominator() + denominator*fr.get_numerator();
    denominator = denominator*fr.get_denominator();
};
Fraction::void operator-= (const Fraction&)
{

};
Fraction::void operator*= (const Fraction&)
{

};
Fraction::void operator/= (const Fraction&)
{

};
Farction operator+(const Fraction& fr, const Fraction& frac)
{
    Fraction f(frac.get_numerator()*fr.get_denominator() + frac.get_denominator()*fr.get_numerator(),
               fr.get_denominator()*frac.get_denominator())
}
