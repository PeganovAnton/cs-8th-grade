#include <iostream>


using namespace std;


int main()
{
  try{
    throw "foo";
  } catch(const char* s) {
    cout << "caught exception '" << s << "'\n";
  }
  try{
    throw "bar";
  } catch(string s) {
    cout << "caught exception '" << s << "'\n";
  }
}
