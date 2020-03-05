#include <iostream>


using std::cout;
using std::cin;
using std::endl;


int main()
{
  int i1, i2, i3, imean;
  double d1, d2, d3, dmean;  // 64bit вещественные числа
  float f1, f2, f3, fmean;   // 32 bit вещественные числа
  cout << "Enter 3 integer numbers\n";
  cin >> i1 >> i2 >> i3;
  imean = (i1 + i2 + i3) / 3;
  cout << imean << endl;

  cout << "Enter 3 real numbers with double precision\n";
  cin >> d1 >> d2 >> d3;
  dmean = (d1 + d2 + d3) / 3;
  cout << dmean << endl;

  cout << "Enter 3 real numbers with single precision\n";
  cin >> f1 >> f2 >> f3;
  fmean = (f1 + f2 + f3) / 3;
  cout << fmean << endl;

  return 0;
}
