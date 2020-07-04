#include <iostream>


using namespace std;


class Fraction
{
    private:
        int32_t numerator;
        uint32_t denominator;
    public:
        Fraction(int32_t, uint32_t);
        int32_t get_numerator()const ;
        uint32_t get_denominator()const;
        void print()const;
        void print_d_n()const;
        float eval()const;
        Fraction reverse()const;
        Fraction operator+ (const Fraction&)const;
        Fraction operator+(int32_t )const;
        double operator+ (double)const;
        //the same for '-', '*', '/'.
        Fraction operator*(Fraction)const;
        Fraction operator*(int32_t)const;
        Fraction operator/ (Fraction)const;
        Fraction operator/ (int32_t)const;

        Fraction operator- ()const;
        //unary minus
        Fraction operator- (Fraction)const;
        Fraction operator- (int32_t)const;
        void operator= (const Fraction&);
        //the same for '+=', '*=, '/=', '-='
        void operator+= (const Fraction&);
        void operator-= (const Fraction&);
        void operator*= (const Fraction&);
        void operator/= (const Fraction&);
};

Fraction operator+ (int32_t, const Fraction&);


double operator+ (double, const Fraction&);
//the same for -, *, /.
Fraction operator* (const Fraction&, const Fraction&);

Fraction operator* (int32_t, const Fraction&);

Fraction operator/ (int32_t, const Fraction&);

Fraction operator/ (const Fraction&, const Fraction&);
