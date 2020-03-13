#include <iostream>
#include <cstdio>


using namespace std;


int main()
{
  char c1, c2;
  c2 = getchar();
  if (c2 == '\n')
    return 0;
  c1 = getchar();
  while (c1 != '\n') {
    if (c1 != 'b' or c2 != 'a')
      cout << c2;
    c2 = c1;
    c1 = getchar();
  }
  cout << c2;
}  
   
