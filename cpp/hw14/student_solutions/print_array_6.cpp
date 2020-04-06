#include <iostream>

using namespace std;

void print_array_6 ( int * p )
{
	for (int j = 0; j<6; j++)
		cout << p[j] << ' ';
}

int main () {
int a [6];
for ( int i = 0; i < 6; i ++)
cin >> a [ i ];
print_array_6 ( a );
return 0;
}
