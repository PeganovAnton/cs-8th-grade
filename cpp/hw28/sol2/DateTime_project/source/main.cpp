#include <iostream>
#include "datetime.hpp"


using namespace std;


int main()
{
    cout << "                                   THE CODE STARTS HERE!!!!!!!!!!!!!!!!!!!!\n";
    Date d1, d2(2, 3, 4);
    cout << d1.str() << endl << d2.str() << endl;
    DateTime d3(2, 3, 4, 5, 6, 7), d4;
    cout << d3.str() << endl;
    cout << d4.str() << endl;
    write_datetime_to_file(d4);
    write_datetime_to_file(d3, "DateTime.txt");
    write_datetime_to_file(d3);
    write_datetime_to_file(d1, "DateTime.txt");
    cout << "is_leap(4) = " << is_leap(4) << endl;
    cout << "is_leap(3) = " << is_leap(3) << endl;
    cout << "is_leap(2000) = " << is_leap(2000) << endl;
    cout << "is_leap(1900) = " << is_leap(1900) << endl;
    cout << "Days in Febrary in leap year = " << (int)d1.get_n_days_in_month(2, 4) << endl;
    cout << "Days in Febrary in not leap year = " << (int)d2.get_n_days_in_month(2, 3) << endl;
    cout << "Days in March in leap year = " << (int)d1.get_n_days_in_month(3, 4) << endl;
    cout << "Days in March in leap year = " << (int)d2.get_n_days_in_month(3, 3) << endl;
    cout << "WrongDateTimeException test\n";
    try
    {
    Date de1(0, 1, 11), de2(1, 0, 11), de3 (13, 1, 11), de4(11, 44, 11);
    DateTime dte1(1, 1, 1, 25, 3, 4), dte2(1, 1, 1, -1, 3, 5), dte3(1, 1, 1, 2, 62, 5), dte4(1, 1, 1, 2, -1, 5), dte5(1, 1, 1, 2, 5, 62);
    DateTime dex1(0, 1, 11, 1, 1, 1), dex2(1, 0, 11, 1, 1, 1), dex3 (13, 1, 11, 1, 1, 1), dex4(11, 44, 11, 1, 1, 1);
    }
    catch(WrongDateTimeException& exc)
    {cout << "WrongDateTimeException is caught; error message is: " << exc.what() << endl;};
}
