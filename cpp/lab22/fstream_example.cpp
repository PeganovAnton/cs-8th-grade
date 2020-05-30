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
  iof.open("ls_file.txt");
  iof >> s;
  cout << "first word: " << s << endl;
  iof >> s;
  cout << "2nd word: " << s << endl;
  iof << "foo" << endl;
  iof.seekp(0);
  iof << "bar" << endl;
  iof >> s;
  cout << "word after seekp: " << s << endl;
  iof.seekg(0);
  iof >> s;
  cout << "1st word: " << s << endl;
  iof.seekg(0);
  getline(iof, s);  // <string>
  cout << "1st line: " << s << endl;
  iof.close();
}
