#include <iostream>
#include <string>


using namespace std;


const int alphabet_size = 'z' - 'a' + 1;
const int case_shift = 'a' - 'A';


void capitalize(string &text)
{
  char diff;
  char prev = 0;
  for(int i=0; i<text.size(); ++i){
    diff = text[i] - 'a';
    if (diff < alphabet_size && diff >= 0 && (prev == ' ' || prev == 0))
      text[i] -= case_shift;
    prev = text[i];
  }
}
      


int main()
{
  string text;
  getline(cin, text);
  capitalize(text);
  cout << text << endl;
}
