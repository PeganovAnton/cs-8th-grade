#ifndef POINT_H
#define POINT_H
class Point
{
  double x, y;
  public:
    Point();
    Point(double, double);
    void set_x(double);
    void set_y(double);
    void print(bool = true);
};
#endif
