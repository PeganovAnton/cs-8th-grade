#include <iostream>
#include <sstream>
#include "datetime.hpp"
#include "itos.hpp"


using namespace std;



Date::Date():day(25), month(12), year(1)
{};
Date::Date(uint8_t d, uint8_t m, int16_t y):day(d), month(m), year(y)
{};
string Date::str()
{
    string s = "";
    s += itos(day)+ '.' + itos(month) + '.' + itos(year);
    return s;
};


DateTime::DateTime():Date(25, 12, 1), hour(0), minute(0), second(0)
{
}
DateTime::DateTime(uint8_t day, uint8_t month, int16_t year, uint8_t h, uint8_t m, uint8_t s):Date(day, month, year)
{
    hour = h;
    minute = m;
    second = s;
}
string DateTime::str()
{
    string s = Date::str();
    s += itos(hour) + ':' + itos(minute) + ':' + itos(second);
    return s;
}
