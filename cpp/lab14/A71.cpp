#include <iostream>
#include <cstdio>
#include <string>


using namespace std;


int main()
{
  int n = -1;
  string s = "";
  char a;
  cin >> n;
  getchar();
  for(int i=0; i<n; i++) {
    s = "";
    while (true) {
      a = getchar();
      if (a == '\n')
       break;
      s += a;
    }
    if (s.size() > 10)
      cout << s[0] << s.size() - 2 << s[s.size()-1] << endl;
    else
      cout << s << endl;
  }
}
