#include <iostream>


using namespace std;


int main()
{
  short int a;
  int b;
  long c;
  for(int i=0; i<10; i++) {
    cin >> a >> b >> c;
    cout << "a + b = " << a + b << endl;
    cout << "b + a = " << b + a << endl;
    cout << "b * c = " << b * c << endl;
    cout << "c * b = " << c * b << endl;
    cout << "b % c = " << b % c << endl;
    cout << "c % b = " << c % b << endl;
  }
}
