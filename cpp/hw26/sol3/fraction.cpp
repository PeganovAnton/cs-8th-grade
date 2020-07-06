#include "fraction.hpp"
#include <iostream>
#include <string>


using namespace std;


//CONSTRUCTORS
Fraction::Fraction():numerator(0), denominator(1)
{}
Fraction::Fraction(double d, int32_t n)
{
    denominator = 1;
    for (int i = 0; i < n; i++)
    {
        d *= 10;
        denominator *= 10;
        //cout << d << " " << denominator << endl;
    }
    numerator =int32_t(d + 0.5 - (d<0));
    //cout << numerator << endl;
    simplify();
}
Fraction::Fraction(int32_t a, uint32_t b)
{
    if (b > 0)
    {
        numerator = a;
        denominator = b;
        this -> simplify();
    }
    else
        cout << "FATAL EROR!" << endl << "The denominator can`t equal 0.";
};

//PRINT
void Fraction::print(bool newline)const
{
    cout << numerator << '/' << denominator;
    if(newline)
        cout << endl;
}
void Fraction::print_d_n()const
{
    cout << denominator << endl << numerator << endl;
};

//GET
int32_t Fraction::get_numerator ()const
{
    return numerator;
}
uint32_t Fraction::get_denominator ()const
{
    return denominator;
};

//MODIFICATION
float Fraction::eval()const
{
    float r = 0;
    r = float(numerator)/denominator;
    return r;
}
  Fraction Fraction::reverse()const
{
    Fraction fr(get_denominator(), get_numerator());
    return fr;
}
void Fraction::simplify()
{
    //cout << "simplify.numerator = "<< numerator << endl;
    //cout << "simplify.denominator = " << denominator << endl;
    uint32_t c = gcd(numerator, denominator);
    //cout << "simplify.c = "<< c << endl;
    numerator /= int32_t(c);
    denominator /= c;
    //cout << "simplify.numerator = "<< numerator << endl;
    //cout << "simplify.denominator = " << denominator << endl;
};

//OPERATOR+
Fraction Fraction::operator+ (const Fraction& fr)const
{
    Fraction frac(numerator*fr.get_denominator()+denominator*fr.get_numerator(),
                  denominator*fr.get_denominator());
    return frac;
}
Fraction Fraction::operator+(int32_t n)const
{
    Fraction fr(numerator+n*denominator, denominator);
    return fr;
}
double operator+(const double d, const Fraction& fr)
{
    return fr.eval() + d;
}
double Fraction::operator+(double d)const
{
    return eval() + d;
};

//OPERATOR-
double Fraction::operator-(double d)const
{
    return eval() - d;
}
Fraction Fraction::operator-(int32_t n)const
{
    Fraction fr(numerator-n*denominator, denominator);
    return fr;
}
Fraction Fraction::operator- (const Fraction& fr)const
{
    Fraction frac(numerator*fr.get_denominator()-denominator*fr.get_numerator(),
                  denominator*fr.get_denominator());
    return frac;
}
Fraction operator- (int32_t n, const Fraction& fr)
{
    Fraction frac = -(fr - n);
    return frac;
}
double operator-(const double d, const Fraction& fr)
{
    return -1*(fr.eval() - d);
}
Fraction Fraction::operator-()const
{
    Fraction fr(numerator*(-1), denominator);
    return fr;
};

//OPERATOR*
double Fraction::operator*(double d)const
{
    return eval() * d;
}
Fraction Fraction::operator*(const Fraction& fr)const
{
    Fraction frac(numerator*fr.get_numerator(), denominator*fr.get_denominator());
    return frac;
}
double operator*(const double d, const Fraction& fr)
{
    return fr.eval() * d;
}
Fraction Fraction::operator*(int32_t n)const
{
    Fraction fr(numerator*n, denominator);
    return fr;
}
Fraction operator* (int32_t n, const Fraction& fr)
{
    Fraction frac = fr * n;
    return frac;
};

//OPERATOR/
double Fraction::operator/(double d)const
{
    return eval() / d;
}
double operator/(const double d, const Fraction& fr)
{
    return fr.eval() / d;
};
Fraction Fraction::operator/ (const Fraction& fr)const
{
    Fraction frac(numerator*fr.get_denominator(), denominator*fr.get_numerator());
    return frac;
}
Fraction Fraction::operator/ (int32_t n) const
{
    Fraction fr (numerator, denominator * n);
    return fr;
}
Fraction operator/(int32_t n, const Fraction& fr)
{
    Fraction frac = fr.reverse()*n;
    return frac;
};

//OPERATOR=
void Fraction::operator=(int32_t n)
{
    numerator = n;
    denominator = 1;
}
void Fraction::operator=(double d)
{
    Fraction fr(d);
    numerator = fr.get_numerator();
    denominator = fr.get_denominator();
}
void Fraction::operator=(const Fraction& fr)
{
    denominator = fr.get_denominator();
    numerator = fr.get_numerator();
    simplify();
}
void operator=(double d, const Fraction& fr)
{
    d = fr.eval();
};

//OPERATOR+=
void Fraction::operator+= (const Fraction& fr)
{
    numerator = numerator*fr.get_denominator() + denominator*fr.get_numerator();
    denominator = denominator*fr.get_denominator();
    simplify();
}
void Fraction::operator+=(double d)
{
    Fraction fr(d);
    numerator = numerator*fr.get_denominator() + denominator*fr.get_numerator();
    denominator = denominator*fr.get_denominator();
    simplify();
}
void Fraction::operator+=(int32_t n);
{
    numerator += n*denominator;
    simplify();
}
void operator+=(double d, const Fraction& fr)
{
    d = fr + d
};

//OPERATOR-=
void Fraction::operator-= (const Fraction& fr)
{
    numerator = numerator*fr.get_denominator() - denominator*fr.get_numerator();
    denominator = denominator*fr.get_denominator();
    simplify();
}
void Fraction::operator-=(double d)
{
    Fraction fr(d);
    numerator = numerator*fr.get_denominator() - denominator*fr.get_numerator();
    denominator = denominator*fr.get_denominator();
    simplify();
}
void Fraction::operator-=(int32_t n);
{
    numerator -= n*denominator;
    simplify();
}
void operator-=(double d, const Fraction& fr)
{
    d = -(fr - d);
};

//OPERATOR*=
void Fraction::operator*= (const Fraction& fr)
{
    numerator = numerator * fr.get_numerator();
    denominator = denominator*fr.get_denominator();
    simplify();
}
void Fraction::operator*=(double d)
{
    Fraction fr(d);
    numerator = numerator * fr.get_numerator();
    denominator = denominator*fr.get_denominator();
    simplify();
}
void Fraction::operator*=(int32_t n);
{
    numerator *= n;
    simplify();
}
void operator-=(double d, const Fraction& fr)
{
    d = fr * d;
};

//OPERATOR/=
void Fraction::operator/= (const Fraction& fr)
{
    numerator *= fr.get_denominator();
    denominator *= fr.get_numerator();
    simplify();
}
void Fraction::operator+=(double d)
{
    Fraction fr(d);
    numerator = numerator*fr.get_denominator();
    denominator = denominator*fr.get_numerator();
    simplify();
}
void Fraction::operator+=(int32_t n);
{
    denominator *= n;
    simplify();
}
void operator-=(double d, const Fraction& fr)
{
    d = d / fr;
};



//OTHERS
uint32_t gcd(int32_t a, int32_t b)
{
    int tmp;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b > 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    };
    return a;
};


//TEMPLATES
template <>
void cout_arg<int>(const int& a)
{
    cout << a;
}

template <>
void cout_arg<double>(const double& a)
{
    cout << a;
}

template <>
void cout_arg<Fraction>(const Fraction& a)
{
    a.print(false);
}


template<>
void print_bin_op<Fraction, double>(const Fraction&a, string op, const double& b)
{
    cout_arg<Fraction>(a);
    cout <<" " << op << " ";
    cout_arg<double>(b);
    cout << " = ";
    if(op == "+")
        cout << a+b << endl;
    if(op == "-")
        cout << a-b << endl;
    if(op == "*")
        cout << a*b << endl;
    if(op == "/")
        cout << a/b << endl;
}

template<>
void print_bin_op<double, Fraction>(const double& a, string op, const Fraction& b)
{
    cout_arg<double>(a);
    cout <<" " << op << " ";
    cout_arg<Fraction>(b);
    cout << " = ";
    if(op == "+")
        cout << a+b << endl;
    if(op == "-")
        cout << a-b << endl;
    if(op == "*")
        cout << a*b << endl;
    if(op == "/")
        cout << a/b << endl;
}


