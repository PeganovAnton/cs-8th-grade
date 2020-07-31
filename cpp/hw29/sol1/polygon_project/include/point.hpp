#ifndef POINT_H
#define POINT_H
#include <string>


class Point
{
  double x, y;
  std::string name;
  public:
    Point();
    Point(double, double, std::string="");
    void set_name(std::string name);
    void set_x(double);
    void set_y(double);
    void print(bool = true);
};
#endif
