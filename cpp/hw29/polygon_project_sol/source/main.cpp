#include <iostream>
#include "point.hpp"
#include "polygon.hpp"


using namespace std;


int main()
{
  Point vertices[3] = {Point(1, 2), Point(2, 1), Point(0, 0)}; 
  Polygon p1(3, vertices);
  cout << "First polygon:\n"; p1.print();

  vertices[0].set_x(-1);

  cout << "####################\nAfter external array modification:\n";
  cout << "First polygon:\n"; p1.print();
  cout << "vertices array:\n"; for(size_t i=0; i<3; ++i) vertices[i].print();

  Polygon p2(p1);
  cout << "\nSecond polygon:\n"; p2.print();

  p2[0] = Point(2, 4); 
  cout << "after `p2` modification,\nFirst polygon:\n"; p1.print();
  cout << "Second polygon:\n"; p2.print();

  cout << "####################\nSubscript operator check\np2[1]: ";
  p2[1].print();
}
