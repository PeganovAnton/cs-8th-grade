#include <iostream>


using namespace std;


class A 
{
  public: 
    virtual void foo() {cout << "in A\n";}
};


class B: public A
{
  public:
    void foo() {cout << "in B\n";}
};


int main()
{
  B b;
  A a, &aref = b, *aptr;
  cout << "B: ";b.foo();
  a = b;
  aref = b;
  aptr = &b;
  cout << "A: "; a.foo();
  cout << "A&: "; aref.foo();
  cout << "A*: "; aptr->foo();
}
