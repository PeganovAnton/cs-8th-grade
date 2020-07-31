#include <exception>
#include <stdint.h>
#include <string>


using namespace std;


string itos(int64_t);


class ValueError: public exception
{
  const string errmsg;
  public:
    ValueError(string errmsg);
    const char* what() const throw();
    ~ValueError() throw();
};


string itos_2d(uint8_t i);

