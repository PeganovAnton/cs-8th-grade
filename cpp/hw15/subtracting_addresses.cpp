#include <iostream>


using namespace std;


void print_stack_main_distance(int a, int* p)
{
  // Указатели мало отличаются, так как обе переменные находятся в стеке.
  cout << "Разность между указателем на локальную переменную в `main()` "
      "и указателем на локальную переменную другой функции:\n" << &a - p 
      << endl;
}


int main()
{
  int a = 0, b = 0, *p = 0;
  p = new int;
  cout << "Разность между указателями на локальные переменные `main()`."
     ":\n" << &a - &b << endl;
  cout << "Разность между указателем на переменную в `main()` "
     "и указателем на переменную в куче (heap):\n" << &a - p 
     << endl;
  stack_main_distance(a, &b);
}
