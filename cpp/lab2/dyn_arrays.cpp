#include <iostream>


using namespace std;


int main()
{
  int *arr, n, m;
  cin >> n;
  m = n;
  arr = new int[n];
  while (n > 0)
    arr[--n] = n;
  for(int i=0; i<m; ++i)
    cout << arr[i] << " ";
  delete[] arr;
}
