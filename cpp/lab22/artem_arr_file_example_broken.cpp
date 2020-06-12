#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>


using namespace std;


int main()
{
	char c;
	string s;
	ifstream ifs;
	ofstream of;
	int n = 0;
	cin >> n;
	int *arr = new int [n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	of.open("test_file_mas.txt");
	for (int i = 0; i < n; i++)
		of << arr[i];
	of.close();

	ifs.open("test_file_mas.txt");
	ifs.seekg(0);
	for (int i = 0; i < n; i++)
	{
		ifs.get(c);
		cout << c << endl;
	}
	ifs.close();

}
