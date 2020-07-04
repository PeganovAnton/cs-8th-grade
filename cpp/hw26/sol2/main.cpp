#include <iostream>
#include "fraction.hpp"


using namespace std;


int main()
{
    int32_t a;
    uint32_t b;
    cin >> a >> b;
    Fraction fr1 (a, b);
    cin >> a >> b;
    Fraction fr2(a, b);
    fr1.print();
    cout << fr1.eval() << endl;
    fr1.reverse().print();
    cout << fr2.get_denominator();
    cout << fr1.get_numerator();
    //fr1*fr2.print();
    cout << endl;
    //fr1/fr2.print();
    cout << endl;
//    fr1-fr2.print();
    cout << endl;
    fr1+fr2.print();
    cout << endl;
    (fr2+1).print();
}
