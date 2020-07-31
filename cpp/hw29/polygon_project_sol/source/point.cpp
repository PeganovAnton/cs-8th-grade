#include <iostream>
#include "point.hpp"


using namespace std;


Point::Point(): x(0), y(0) {}

Point::Point(double x, double y): x(x), y(y) {}

void Point::set_x(double x) {this->x = x;}

void Point::set_y(double y) {this->y = y;}

void Point::print(bool newline)
{
  cout << "(" << x << ", " << y << ")";
  if (newline)
    cout << endl;
}

