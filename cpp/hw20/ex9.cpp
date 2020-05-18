#include <cstdio>
#include <string>


using namespace std;


int main()
{
  int begin = 0, end = -1, space_count = 0, i;
  char c;
  string w;
  c = getchar();
  while (c != '\n'){
    if (c == ' '){
      space_count++;
      if (space_count % 2 == 0){
        for(i=w.size()-1; i>=0; i--)
           putchar(w[i]);
        w = "";
      }
      putchar(' ');
    } else
      if (space_count % 2 == 0)
        putchar(c);
      else
        w += c;
    c = getchar();
  }
  if (space_count % 2 == 1){
    for(i=w.size()-1; i>=0; i--)
      putchar(w[i]);
    w = "";
  }
  putchar('\n');
}

