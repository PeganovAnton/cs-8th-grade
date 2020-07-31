#include<iostream>
#include "point.hpp"
#include <string>


using namespace std;


Point::Point():x(0), y(0), name(""){};
Point::Point(double dx, double dy, string s):x(dx), y(dy), name(s){};
void Point::set_x(double dx){x = dx;};
void Point::set_y(double dy){y = dy;};
void Point::set_name(string s){name = s;};
void Point::print(bool b)
{
    cout << name << "(" << x << "; " << y << ")";
    if(b)
        cout << endl;
};
