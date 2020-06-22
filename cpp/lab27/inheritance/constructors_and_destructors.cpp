#include <iostream>


using namespace std;


class A
{
  public:
    A(){cout << "constructor of A\n";}
    ~A(){cout << "destructor of A\n";}
};


class B: public A
{
  public:
    B(){cout << "constructor of B\n";}
    ~B(){cout << "destructor of B\n";}
};


int main()
{
  B b;
}
