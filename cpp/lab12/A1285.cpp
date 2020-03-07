#include <iostream>
#include <string>

using namespace std;

int main()
{
  int l, r, n, i, t;
  string s;
  cin >> n;
  r = 0;
  l = 0;
  for (i = 0; i < n; i++)
  {
    cin >> s;
    if (s == "R")
      r+=1;
    else
      s+=1;
  }
  cout << s+t+1;
}
