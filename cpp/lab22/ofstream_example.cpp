#include <fstream>
#include <iostream>
#include <string>


using namespace std;


int main()
{
  ofstream of;
  ifstream if_;
  fstream iof;
  string hw = "Hello World", file_name = "hello_world.txt";
  of.open(file_name);
  of << hw << endl;
  of.close();
}
