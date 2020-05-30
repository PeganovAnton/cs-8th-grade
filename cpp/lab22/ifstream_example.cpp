#include <fstream>
#include <iostream>
#include <string>


using namespace std;


int main()
{
  ofstream of;
  ifstream if_;
  fstream iof;
  string hw = "Hello World", s;
  if_.open("ls_file.txt");
  if_ >> s;
  cout << "first word: " << s << endl;
  if_ >> s;
  cout << "2nd word: " << s << endl;
  if_.seekg(0);
  if_ >> s;
  cout << "1st word: " << s << endl;
  if_.seekg(0);
  getline(if_, s);  // <string>
  cout << "1st line: " << s << endl;
  if_.close();
}
