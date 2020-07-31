#include <iostream>
#include <sstream>
#include "datetime.hpp"
#include "itos.hpp"
#include <cstdint>


using namespace std;



const uint8_t Date::n_days_in_month[12] =
                {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


WrongDateTimeException::WrongDateTimeException(const string& msg):msg(msg)
{}
const char* WrongDateTimeException::what() const throw()
{
    return msg.c_str();
}


Date::Date():day(25), month(12), year(1)
{};
Date::Date(uint8_t d, uint8_t m, int16_t y)
{
    if(m <= 0)
        throw (WrongDateTimeException("The number of month can`t be less then 1!"));
    if(m > 12)
        throw (WrongDateTimeException("The number of month can`t be more then 12!(There are only 12 months in year)"));
    if(d < 0)
        throw (WrongDateTimeException("The number of day must be plural!"));
    uint8_t ndm = get_n_days_in_month(m, y);
    if(d > ndm)
    {
        string s = "There are only " + itos(ndm) + " in this month!";
        throw (WrongDateTimeException(s));
    }
    day = d;
    month = m;
    year = y;
};
string Date::str() const
{
    string s = "";
    s += itos(day)+ '.' + itos(month) + '.' + itos(year);
    return s;
};


bool is_leap(uint16_t n)
{
    if (n % 4 == 0)
    {
    if(n % 400 == 0)
        return true;
    else
        if(n % 100 != 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

uint8_t Date::get_n_days_in_month(uint8_t n, uint16_t ny)
{
    if(n != 2)
        return n_days_in_month[n];
    else
        if(is_leap(ny))
            return 29;
        else
            return 28;
}

DateTime::DateTime():Date(25, 12, 1), hour(0), minute(0), second(0)
{
}
DateTime::DateTime(uint8_t day, uint8_t month, int16_t year, uint8_t h, uint8_t m, uint8_t s):Date(day, month, year)
{
    if(h > 24)
        throw (WrongDateTimeException ("There are only 24 hours in day!"));
    if(h < 0)
        throw (WrongDateTimeException ("The number of hour must be plural!"));
    if(m > 60)
        throw(WrongDateTimeException ("There are only 60 minutes in hour!"));
    if(m < 0)
        throw(WrongDateTimeException("The number of minute must be plural!"));
    if(s > 60)
        throw(WrongDateTimeException ("There are only 60 seconds in a minute!"));
    if(s < 0)
        throw (WrongDateTimeException("The number of second must be plural!"));
    hour = h;
    minute = m;
    second = s;
}
string DateTime::str() const
{
    string s = Date::str();
    s += ' ';
    if(hour < 10)
        s += '0';
    s += itos(hour) + ':';
    if(minute < 10)
        s += '0';
    s+= itos(minute) + ':';
    if(second < 10)
        s += '0';
    s+= itos(second);
    return s;
}




void write_datetime_to_file(const Date& d, const string f_name)
{
    ofstream ofs(f_name, ios::app);
    ofs << d.str() << endl;
}
