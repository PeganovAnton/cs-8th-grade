#include <iostream>
#include <string>


using namespace std;


int main()
{
	int tmp = 0, yes = 0;
	string s1, s2;
	cin >> s1, s2;
	s1 += s2;
	cin >> s2;
	if(s1.size() == s2.size())
	{
		for(int i = 0; i <= s2.size(); i++)
		{
			for(int j = 0; j <= s1.size(); j++)
				if (s2[i] == s1[j])
				{
					s1.erase(j, 1);
					break;
				}
				else
					tmp++;
			if(tmp >= s1.size())
			{
				cout << "NO";
				break;
			}
			else
				yes++;
		}
		if(yes >= s2.size())
			cout << "YES";
		else
			cout << "NO";
	}
	else
		cout << "NO";
}
