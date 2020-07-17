#include <iostream>
#include "datetime.hpp"


using namespace std;


int main()
{
    cout << "                                   THE CODE STARTS HERE!!!!!!!!!!!!!!!!!!!!\n";
    Date d1, d2(2, 3, 4);
    cout << d1.str() << endl << d2.str() << endl;
    DateTime d3(2, 3, 4, 5, 6, 7);
    cout << d3.str() << endl;
}
