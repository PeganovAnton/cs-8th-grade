#include <iostream>
#include <stdint.h>


using namespace std;


class A
{
  int32_t a;
};


class B: public A
{
  int32_t a;
};


int main()
{
  cout << "sizeof(A): " <<  sizeof(A) << endl;  // Печатает 4.

  // Печатает 8, так как содержит в том числе родительские члены.
  cout << "sizeof(B): " <<  sizeof(B) << endl;  
}
