#include <iostream>


using namespace std;


class A
{
  public:
    void bar(){spam();}
    
    //virtual
    void spam(){cout << "spam in A\n";}
};


class B: public A
{
  public:
    void foo(){bar();}
    void spam(){cout << "spam in B\n";}
};


int main()
{
  B b;
  b.foo();  
  // Печатает 'in A', если метод `spam()` не виртуальный и 'in B', если
  // метод `spam()` -- виртуальный.
}
