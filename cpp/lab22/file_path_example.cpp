#include <fstream>
#include <iostream>
#include <string>


using namespace std;


void print_ith_line(ifstream &ifs, int li)
{
  int count = 0;
  string s;
  while(count <= li){
    count++;
    getline(ifs, s);
  }
  cout << s << endl;
}


int main()
{
  int li = 0;
  ifstream abs_ifs, rel_ifs;
  cin >> li;
  const char* abs_path = "/home/anton/struct_example.cpp";
  const char* rel_path = "../../../../../../../struct_example.cpp";
  abs_ifs.open(abs_path);
  rel_ifs.open(rel_path);
  print_ith_line(abs_ifs, li);
  print_ith_line(rel_ifs, li);
}
