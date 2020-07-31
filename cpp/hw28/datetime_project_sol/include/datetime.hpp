#include <exception>
#include <fstream>
#include <stdint.h>
#include <string>


using namespace std;


class WrongDateTimeException: public exception
{
  const string errmsg;
  public:
    WrongDateTimeException(string errmsg);
    const char* what() const throw();
    ~WrongDateTimeException() throw();
};


class Date
{
  static const uint8_t n_days_in_month[];
  static const uint8_t n_months_in_year = 12;
  uint8_t day;
  uint8_t month;
  int16_t year;
  public:
    Date();
    Date(uint8_t day, uint8_t month, int16_t year); 
    static uint8_t get_n_days_in_month(uint8_t, int16_t);
    static uint8_t get_n_days_in_february(int16_t);   
    void increment();
    void decrement();
    Date operator++();
    Date operator++(int);
    Date operator--();
    Date operator--(int);
    Date operator+(int) const;
    Date operator-(int) const;
    Date& operator+=(int);
    Date& operator-=(int);
    virtual string str() const;
};

Date operator+(int n, const Date& d);

class DateTime: public Date
{
  static const uint8_t n_hours_in_day = 24;
  static const uint8_t n_minutes_in_hour = 60;
  static const uint8_t n_seconds_in_minute = 60;
  uint8_t second; 
  uint8_t minute; 
  uint8_t hour; 
  public:
    DateTime();
    DateTime(
        uint8_t hour, 
        uint8_t minute, 
        uint8_t second, 
        uint8_t day, 
        uint8_t month, 
        int16_t year);
    string get_time_string() const;
    string str() const;
};

void write_date_time_to_file(const Date&, const string&);
