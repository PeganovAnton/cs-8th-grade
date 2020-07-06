#include <iostream>
#include "fraction.hpp"


using namespace std;






int main()
{
    int32_t a = 2;
    uint32_t b = 3;
    //cout << gcd(a, b) << endl;
    Fraction fr1 (a, b);
    a = 4;
    b = 5;
    Fraction fr2(a, b);
    fr1.print();
    cout <<"("; fr1.print(false); cout << ").eval() = " <<  fr1.eval() << endl;
    fr1.reverse().print();
    cout << "fr1.get_denominator: "<< fr2.get_denominator() << endl;
    cout << "fr1.get_numerator: " << fr1.get_numerator() << endl;
    print_bin_op<Fraction, Fraction>(fr2, "+", fr1);
    print_bin_op<Fraction, Fraction>(fr2, "-", fr1);
    print_bin_op<Fraction, Fraction>(fr1, "*", fr2);
    print_bin_op<Fraction, Fraction>(fr1, "/", fr2);

    print_bin_op<Fraction, Fraction>(fr2, "+=", fr1);
    print_bin_op<Fraction, Fraction>(fr2, "-=", fr1);
    print_bin_op<Fraction, Fraction>(fr1, "*=", fr2);
    print_bin_op<Fraction, Fraction>(fr1, "/=", fr2);

    print_bin_op<Fraction, int32_t>(fr2, "+", 1);
    print_bin_op<Fraction, int32_t>(fr2, "-", 1);
    print_bin_op<Fraction, int32_t>(fr2, "*", 3);
    print_bin_op<Fraction, int32_t>(fr2, "/", 4);

    print_bin_op<Fraction, int32_t>(fr2, "+=", 1);
    print_bin_op<Fraction, int32_t>(fr2, "-=", 1);
    print_bin_op<Fraction, int32_t>(fr2, "*=", 3);
    print_bin_op<Fraction, int32_t>(fr2, "/=", 4);

    print_bin_op<int32_t, Fraction>((int32_t)1, "+", fr2);
    print_bin_op<int32_t, Fraction>((int32_t)1, "-", fr2);
    print_bin_op<int32_t, Fraction>((int32_t)3, "*", fr2);
    print_bin_op<int32_t, Fraction>((int32_t)4, "/", fr2);

    print_bin_op<int32_t, Fraction>((int32_t)1, "+=", fr2);
    print_bin_op<int32_t, Fraction>((int32_t)1, "-=", fr2);
    print_bin_op<int32_t, Fraction>((int32_t)3, "*=", fr2);
    print_bin_op<int32_t, Fraction>((int32_t)4, "/=", fr2);
    double d;
    cout << "Enter real number and integer for "
            "debugging of Fraction(double) constructor\n";
    cin >> d;
    int n;
    cin >> n;
    Fraction frd(d, n);
    frd.print();
    print_bin_op<double, Fraction>(1.2, "+", Fraction(-1.0, 4));
    print_bin_op<double, Fraction>(1.2, "-", Fraction(-1.0, 4));
    print_bin_op<double, Fraction>(1.2, "*", Fraction(-1.0, 4));
    print_bin_op<double, Fraction>(1.2, "/", Fraction(-1.0, 4));

    print_bin_op<double, Fraction>(1.2, "+=", Fraction(-1.0, 4));
    print_bin_op<double, Fraction>(1.2, "-=", Fraction(-1.0, 4));
    print_bin_op<double, Fraction>(1.2, "*=", Fraction(-1.0, 4));
    print_bin_op<double, Fraction>(1.2, "/=", Fraction(-1.0, 4));
}
