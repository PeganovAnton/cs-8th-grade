#include <iostream>


using namespace std;


void inc_static()
{
  static int var = 0;
  cout << "var = " << var << endl;
  var++;
}


int main()
{
  inc_static();
  inc_static();
  inc_static();
}
