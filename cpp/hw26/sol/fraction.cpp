#include <iostream>


using namespace std;


class fraction
{
    private:
        int integer, x, y;
    public:

        fraction(int a, b)
        {
            x = a;
            y = b;
            if(x > y)
                integer = x/y;
            x = x % y;
        }

        void print()
        {
            int i = 0, copy = 0;
            if(integer > 0)
            {
                copy = integer;
                while(copy > 0)
                {
                    i++;
                    copy /= 10;
                }
            }
            for (int j = 0; j < i; j++)
                cout << ' ';
            cout << x;
            if(integer > 0)
                cout << integer;
            for(int j = 0; j < i; j++)
                cout << ' ';
            cout << y;
        }

        float eval()
        {
            float r;
            r = integer + x / y;
            return r;
        }

        fraction reverse()
        {
            fraction fr;
            int tmp = 0;
            tmp = y;
            y = x + integer*y;
            x = tmp;
        }
};


int main()
{

}
