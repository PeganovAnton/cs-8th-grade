#include <fstream>
#include <iostream>


using namespace std;


class WrongDateTimeException: public exception
{
    private:
        const string msg;
    public:
        WrongDateTimeException(const string&);
        const char* what() const throw();
};


class Date
{
private:
    uint8_t day;
    uint8_t month;
    int16_t year;
public:
    static const uint8_t n_days_in_month[12];
    static uint8_t get_n_days_in_month(uint8_t, uint16_t);
    Date();
    Date(uint8_t, uint8_t, int16_t);
    virtual string str() const;
};

bool is_leap(uint16_t);

class DateTime: public Date
{
private:
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
public:
    static const uint8_t n_hours_in_day = 24;
    static const uint8_t n_minutes_in_hour = 60;
    static const uint8_t n_seconds_in_minute = 60;
    DateTime();
    DateTime(uint8_t, uint8_t, int16_t, uint8_t, uint8_t, uint8_t);
    string str() const;

};

void write_datetime_to_file(const Date& , const string = "Date.txt");
