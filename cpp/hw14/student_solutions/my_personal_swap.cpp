#include <iostream>

using namespace std;


void my_personal_swap ( int * a , int * b )
{
	int *save;
	if (*a != NULL)
		if (*b != NULL)
		{
			save = & *a;
			a = & *b;
			b = & *save;
		}
}

int main () 
{
	int a , b ;
	cin >> a >> b ;
	my_personal_swap (& a , & b );
	cout << a << " " << b << endl ;
	my_personal_swap (& a , NULL );
	my_personal_swap ( NULL , & b );
	my_personal_swap ( NULL , NULL );
	return 0;
}
