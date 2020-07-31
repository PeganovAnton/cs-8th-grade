#include <iostream>

#include "datetime.hpp"


using namespace std;


int main()
{
  Date d1;
  cout << d1.str() << endl;
  for(size_t i=0; i<10; ++i) d1++;
  for(size_t i=0; i<10; ++i) d1--;
  cout << d1.str() << endl;
  d1 -= 365;
  cout << d1.str() << endl;
  d1 += 365000;
  cout << d1.str() << endl;
  Date d2 = d1 + 10;
  Date d3 = d2 - 10;
  Date d4 = 40 + d1;
  cout << d2.str() << endl;
  cout << d3.str() << endl;
  cout << d4.str() << endl;
  cout << int(Date::get_n_days_in_month(1, 2000)) << endl;
  cout << int(Date::get_n_days_in_month(2, 2000)) << endl;
  cout << int(Date::get_n_days_in_month(2, 1900)) << endl;

  DateTime dt;
  cout << dt.str() << endl;
  const string fn = "my_file.txt";
  write_date_time_to_file(d1, fn);
  write_date_time_to_file(dt, fn);
  cout << int(Date::get_n_days_in_month(-1, 1900)) << endl;
}
