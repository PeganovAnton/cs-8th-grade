#include <cstdlib>
#include <iostream>


using namespace std;


int main(int argc, char *argv[])
{
  cout << "argc: " << argc << endl;
  int num = atoi(argv[1]);
  cout << "executable name: " << argv[0] << endl;
  cout << "(" << num << ")^2 = " << num * num << endl;
}
