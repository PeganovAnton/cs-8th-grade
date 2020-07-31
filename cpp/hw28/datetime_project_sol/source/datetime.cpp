#include <exception>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <string>

#include "datetime.hpp"
#include "itos.hpp"


using namespace std;


WrongDateTimeException::WrongDateTimeException(string errmsg): 
    errmsg(errmsg) {}
    
const char* WrongDateTimeException::what() const throw() 
    {return errmsg.c_str();}

WrongDateTimeException::~WrongDateTimeException() throw() {}



Date::Date(): day(25), month(12), year(1) {}

Date::Date(uint8_t day, uint8_t month, int16_t year)
{
  string errmsg;
  if (day < 1 || day > get_n_days_in_month(month, year)){
    errmsg = "Wrong day number " 
      + itos(day) 
      + " in month " + itos(month) + "\n";
    throw WrongDateTimeException(errmsg);
  } else
    day = day;

  if (month < 1 || month > n_months_in_year){
    errmsg = "Wrong month number " + itos(month) + "\n";
    throw WrongDateTimeException(errmsg);
  } else
    month = month;   

  if (year == 0){
    errmsg = "There is no zeroth year\n";
    throw WrongDateTimeException(errmsg);
  } else
    year = year;
}

uint8_t Date::get_n_days_in_month(uint8_t month, int16_t year)
{
  string errmsg;
  if (month < 1 || month > n_months_in_year){
    errmsg = "Wrong month number " + itos(month) + "\n";
    throw WrongDateTimeException(errmsg);
  }  

  if (year == 0){
    errmsg = "There is no zeroth year\n";
    throw WrongDateTimeException(errmsg);
  } 
      
  if (month == 2)
    return get_n_days_in_february(year);
  else {
    int idx = month - 1;
    return n_days_in_month[idx];
  }
}

uint8_t Date::get_n_days_in_february(int16_t year)
{
  string errmsg;
  if (year == 0){
    errmsg = "There is no zeroth year\n";
    throw WrongDateTimeException(errmsg);
  }
  if (year < 1)
    year++;
  uint8_t n_days;
  if (year % 400 == 0)
    n_days = 29;
  else if (year % 100 == 0)
    n_days = 28;
  else if (year % 4 == 0)
    n_days = 29;
  else
    n_days = 28;
  return n_days;
}
    
void Date::increment()
{
  ++day;
  if (day > get_n_days_in_month(month, year)){
    day = 1;
    ++month;
  }
  if (month > n_months_in_year){
    month = 1;
    ++year;
  }
  if (year == 0)
    year = 1;
}

void Date::decrement()
{
  --day;
  if (day < 1){
    --month;
  }
  if (month < 1){
    --year;
    month = 12;
  }
  if (year == 0)
    year = -1;
  if (day < 1)
    day = get_n_days_in_month(month, year);
}

Date Date::operator++()
{
  increment();
  return Date(*this);
}

Date Date::operator++(int)
{
  Date date(*this);
  increment();
  return date;
}

Date Date::operator--()
{
  decrement();
  return Date(*this);
}

Date Date::operator--(int)
{
  Date date(*this);
  decrement();
  return date;
}
 
Date Date::operator+(int n) const
{
  Date d = *this;
  if (n < 0){
    n = -n;
    for(size_t i=0; i<n; i++)
      d.decrement();
  }
  else
    for(size_t i=0; i<n; i++)
      d.increment();
  return d;
}

Date Date::operator-(int n) const
{
  return *this + (-n);
}

Date& Date::operator+=(int n)
{
  if (n < 0){
    n = -n;
    for(size_t i=0; i<n; ++i)
      decrement();
  } else
    for(size_t i=0; i<n; ++i)
      increment();
  return *this;
}

Date& Date::operator-=(int n)
{
  return *this += -n;
}

string Date::str() const
{
  string year_str = itos(abs(year));
  if (year < 0)
    year_str += " BC";
  return itos_2d(day) + "." + itos_2d(month) + "." + year_str;
}


Date operator+(int n, const Date& d)
{
  return d + n;
}


DateTime::DateTime(): second(0), minute(0), hour(0) {}

DateTime::DateTime(
    uint8_t hour, 
    uint8_t minute, 
    uint8_t second, 
    uint8_t day, 
    uint8_t month, 
    int16_t year) : Date(day, month, year)
{
  string errmsg;
  if (hour >= n_hours_in_day){
    errmsg = "Wrong hour " + itos(hour) + "\n";
    throw WrongDateTimeException(errmsg);
  } else
    hour = hour;
  if (minute >= n_minutes_in_hour){
    errmsg = "Wrong minute " + itos(minute) + "\n";
    throw WrongDateTimeException(errmsg);
  } else
    minute = minute;   
  if (second > n_seconds_in_minute){
    errmsg = "Wrong second " + itos(second) + "\n";
    throw WrongDateTimeException(errmsg);
  } else
    second = second;   
}

string DateTime::get_time_string() const
{
  return itos_2d(hour) + ":" + itos_2d(minute) + ":" + itos_2d(second);
}

string DateTime::str() const
{
  return get_time_string() + " " + Date::str(); 
}


const uint8_t Date::n_days_in_month[] = 
    {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void write_date_time_to_file(const Date& d, const string& fn)
{
  ofstream ofs(fn.c_str(), ios::out | ios::app);
  ofs << d.str() << endl;
  ofs.close();
}
