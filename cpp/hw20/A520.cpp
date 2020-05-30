#include <iostream>
#include <string>


using namespace std;


int main()
{
	const int as = 'z' - 'a' + 1, cs = 'a' - 'A';
	int alphabet[as], ans = 0, n = 0;
	string s;
	cin >> n;
	cin >> s;
	if (n >= as)
	{
		for (int i = 0; i < n; i++)
		{
      if (s[i] >= 'a')                                                         
        s[i] -= cs; 
			cout << s[i] << ' ';   
			if (alphabet[s[i] - 2*cs] != 1)
			{
				alphabet [s[i] - 2*cs] = 1;
				ans++;
				cout << ans << endl;
			}
		}
		if(ans >= as)
			cout << "YES";
		else
			cout << "NO";
	}
	else
		cout << "NO";
}
