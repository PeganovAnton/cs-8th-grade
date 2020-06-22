#include <iostream>
#include <stdint.h>


using namespace std;


class A
{
  int32_t a;
  public:
    void foo(int32_t x)
    {
      cout << x << endl;
    }
};


class B
{
  int32_t a;
  public:
    virtual void foo(int32_t x)
    {
      cout << x << endl;
    }
};


int main()
{
  A a;
  // Печатает 4, потому что класс содержит только переменную `A.a`.
  cout << "sizeof(A): " << sizeof(A) << endl;
  cout << "sizeof(a): " << sizeof(a) << endl;

  B b;
  // Печатает 16, потому что класс содержит указатель на `B.foo()` в таблице 
  // виртуальных функций.
  cout << "sizeof(B): " << sizeof(B) << endl;
  cout << "sizeof(b): " << sizeof(b) << endl;
}
