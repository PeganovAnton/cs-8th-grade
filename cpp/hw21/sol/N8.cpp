#include <iostream>
#include <string>
#include <cstdio>


using namespace std;


int main()
{
	int i = 1, j = 0;;
	char c;
	string s, stmp;
	while (c != '\n')
	{
		while (c != ' ')
		{
			c = getchar();
			if (i % 2 == 0) 
				stmp = c + stmp;
			else
				stmp += c;
		}
		i++;
		s += ' ' + stmp;
		stmp = "";
	}
	cout << s;
}
