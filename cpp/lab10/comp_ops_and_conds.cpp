#include <iostream>


using std::cout;
using std::cin;
using std::endl;


int main()
{
  int a, b;
  cin >> a >> b;
  if (a == b)
    cout << "a and b are equal\n";
  else
    cout << "a and b are not equal\n";
  if (a >= b)
    cout << "a is greater or equal than b\n";
  if (a < b) {
    cout << "a is less than b";
    cout << endl;
  }
  if (a != b) 
    cout << "a is not equal to b\n";

}
