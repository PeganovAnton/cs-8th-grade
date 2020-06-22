#include <iostream>


using namespace std;


class A
{
  public:
    void foo() const {cout << "foo A\n";}
};


class B: public A
{
  public:
    void foo() const {cout << "foo B\n";}
};


int main()
{
  B b;
  b.foo();
}
