#include <iostream>


using std::cout;
using std::cin;
using std::endl;


int main()
{
  int n, count;
  cin >> n;
  count = n / 2;
  cout << count << endl;
  if (n % 2 > 0) {
    cout << 3 << " ";
    n -= 3;
  }
  while (n > 0) {
    cout << 2 << " ";
    n -= 2;
  }
  return 0;
}
