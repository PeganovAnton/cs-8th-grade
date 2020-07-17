#include <iostream>


using namespace std;


class Date
{
private:
    uint8_t day;
    uint8_t month;
    int16_t year;
public:
    Date();
    Date(uint8_t, uint8_t, int16_t);
    virtual string str();
};

class DateTime: public Date
{
private:
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
public:
    DateTime();
    DateTime(uint8_t, uint8_t, int16_t, uint8_t, uint8_t, uint8_t);
    string str();

};
