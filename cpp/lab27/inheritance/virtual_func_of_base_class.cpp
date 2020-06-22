#include <iostream>


using namespace std;


class A
{
  int x;
  public:
    A(int x){this->x = x;}
    virtual void foo() {cout << "x: " << x << endl;}
};


class B: public A
{
  int x;
  public:
    B(int x):A(x-1){this->x = x;}
    void bar(){foo();}
    int get_x(){return x;}
};


int main()
{ 
  int x;
  cin >> x;
  B b(x);

  // Берется `x` из класса `A`, так как функция `foo()` определена 
  // в классе `A`, а в классе `B` функции `foo()` нет. 
  b.bar();
  cout << "get b.x: " << b.get_x() << endl;
}
