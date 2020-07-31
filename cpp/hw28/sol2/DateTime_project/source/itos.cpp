#include <string>
#include <sstream>
#include "itos.hpp"


using namespace std;


string itos(int64_t i)
{
  ostringstream oss;
  oss << i;
  return oss.str();
}
