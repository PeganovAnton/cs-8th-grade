#include <iostream>


using namespace std;


int factorial_while(int n)
{
  int r;
  r = 1;
  while (n > 1) {
    r *= n;
    n--;  // уменьшить `n` на 1 (оператор декремента)
  }
  return r;
}


int factorial_for(int n)
{
  int r, i;
  r = 1;
  for(
      i=2 /*инициализация переменной цикла (счетчика)*/; 
      i<=n /*условие продолжения цикла*/; 
      i++ /*обновление переменной цикла*/)  // `i++` -- увеличить `i` на 1 (оператор инкремента)
    r *= i;
  return r;
}


int main()
{
  int n;
  cin >> n;
  cout << "factorial while\n" << n << "! = " << factorial_while(n) << endl << endl;
  cout << "factorial for\n" << n << "! = " << factorial_for(n) << endl;
  return 0;
}
