#include <exception>
#include <sstream>
#include <stdint.h>
#include <string>


using namespace std;


string itos(int64_t i)
{
  ostringstream oss;
  oss << i;
  return oss.str();
}


ValueError::ValueError(string errmsg): errmsg(errmsg) {}

const char* ValueError::what() const throw() {return errmsg.c_str();}

ValueError::~ValueError() throw() {}


string itos_2d(uint8_t i)
{
  if (i > 99)
    throw ValueError("Argument of `itos_2d` has to be less than 100 whereas "
      "it is equal to " + itos(i));
  string s = itos(i);
  if (s.size() == 1)
    s = "0" + s;
  return s;
}

