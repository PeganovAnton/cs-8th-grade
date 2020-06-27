#include <iostream>


using namespace std;


class A
{
  int x, y;
  public:
    A(int x, int y): x(x), y(y) {}
    void print() {cout << "A::x = " << x << ", A::y = " << y << endl;}
};


int main()
{
  A a1(1, 2);
  A a2(a1);
  a2.print();
}
