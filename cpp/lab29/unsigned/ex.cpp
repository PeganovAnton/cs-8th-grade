#include <iostream>
#include <stdint.h>


using namespace std;


int main()
{
  int n;
  int s, ss;
  unsigned int u = 5;
  cin >> n;
  cout << "(uint32_t)n: " << (uint32_t)n << endl;
  s = n + u;
  cout << n << " + " << u << " = " << s << endl;
  s = u + n;
  cout << u << " + " << n << " = " << s << endl;
  s = n * u;
  cout << n << " * " << u << " = " << s << endl;
  s = u * n;
  cout << u << " * " << n << " = " << s << endl;
  s = n - u;
  cout << n << " - " << u << " = " << s << endl;
  s = u - n;
  cout << u << " - " << n << " = " << s << endl;
  s = n / u;  // на самом деле происходит `s = (uint32_t)n / u
  cout << n << " / " << u << " = " << s << endl;
  s = u / n;  // `s = u / (uint32_t)n
  cout << u << " / " << n << " = " << s << endl;
  cout << endl;
  cout << n << " + " << u << " = " << n + u << endl;
  cout << u << " + " << n << " = " << u + n << endl;
  cout << endl;
  u = 2147483647;
  cout << "(int)2^31-1 = " << (int)u << endl;
  u = 2147483648;
  cout << "(int)2^31 = " << (int)u << endl;
  u = 5;
  s = n / (int)u;  // n / int(u)
  cout << n << " / " << "(int)" <<  u << " = " << s << endl;
  s = (int)u / n;  // int(u) / n
  cout << "(int)" << u << " / " << n << " = " << s << endl;

}
