#include <iostream>
#include <stdint.h>
#include <string>
#include <typeinfo>

using namespace std;


class Fraction
{
    private:
        int32_t numerator;
        uint32_t denominator;
    public:
        Fraction();
        Fraction (double, int32_t = 3);
        Fraction(int32_t, uint32_t);

        int32_t get_numerator()const ;
        uint32_t get_denominator()const;

        void print(bool = true)const;
        void print_d_n()const;

        float eval()const;
        Fraction reverse()const;
        void simplify();

        Fraction operator+ (const Fraction&)const;
        Fraction operator+(int32_t )const;
        double operator+ (double)const;

        double operator- (double)const;
        Fraction operator- ()const;
        //unary minus
        Fraction operator- (const Fraction&)const;
        Fraction operator- (int32_t)const;

        double operator* (double)const;
        Fraction operator*(const Fraction&)const;
        Fraction operator*(int32_t)const;

        double operator/ (double)const;
        Fraction operator/ (const Fraction&)const;
        Fraction operator/ (int32_t)const;

        void operator= (const Fraction&);
        void operator=(double);
        void operator=(int32_t n);

        void operator+= (const Fraction&);
        void operator+=(double);
        void operator+=(int32_t n);

        void operator-= (const Fraction&);
        void operator-=(double);
        void operator-=(int32_t n);

        void operator*= (const Fraction&);
        void operator*=(double);
        void operator*=(int32_t n);

        void operator/= (const Fraction&);
        void operator/=(double);
        void operator/=(int32_t n);
};

Fraction operator+ (int32_t, const Fraction&);
double operator+ (double, const Fraction&);

double operator- (double, const Fraction&);
Fraction operator- (int32_t, const Fraction&);

Fraction operator/ (int32_t, const Fraction&);
double operator/ (double, const Fraction&);

Fraction operator* (int32_t, const Fraction&);
double operator* (double, const Fraction&);

//void operator=(int32_t, const Fraction&);
void operator=(double, const Fraction&);

//void operator+=(int32_t, const Fraction&);
void operator+=(double, const Fraction&);

//void operator-=(int32_t, const Fraction&);
void operator-=(double, const Fraction&);

//void operator*=(int32_t, const Fraction&);
void operator*=(double, const Fraction&);

//void operator/=(int32_t, const Fraction&);
void operator/=(double, const Fraction&);





uint32_t gcd(int32_t, int32_t);





template <class A>
void cout_arg(const A& a);


template<class A, class B>
void print_bin_op(const A&a, string op, const B& b)
{
    cout_arg<A>(a);
    cout <<" " << op << " ";
    cout_arg<B>(b);
    cout << " = ";
    if(op == "+")
        (a+b).print();
    if(op == "-")
        (a-b).print();
    if(op == "*")
        (a*b).print();
    if(op == "/")
        (a/b).print();
}
template<>
void print_bin_op<Fraction, double>(const Fraction&a, string op, const double& b);


template<>
void print_bin_op<double, Fraction>(const double& a, string op, const Fraction& b);
