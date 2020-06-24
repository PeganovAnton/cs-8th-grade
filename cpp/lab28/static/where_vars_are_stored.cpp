#include <iostream>


using namespace std;


int global_var;


int* print_addr_diff_with_local_var(int *b)
{
  int a;
  cout << "&local_var_in_main - &local_var_in_other_func = " << &a - b << endl;
}


int main()
{
  int local_var;
  static int static_var;
  cout << "&local_var - &global_var = " << &local_var - &global_var << endl;
  cout << "&local_var - &static_var = " << &local_var - &static_var << endl;
  cout << "&static_var - &global_var = " << &static_var - &global_var << endl;
  print_addr_diff_with_local_var(&local_var);
}
