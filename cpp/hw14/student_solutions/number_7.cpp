#include <iostream>

using namespace std;


void my_slightly_less_dumb_reallocation(
		int ** source , unsigned int n_old , unsigned int n_new )
{
	if (n_new > 0)
	{
		if (n_old < n_new)
			n_new = n_old;
		int *arr = new int [n_new];
		if (*source != NULL)
			for (int i = 0; i < n_new; i++)
				arr[i]= *source[i];
		*source = arr;
	}
}


int main() 
{
  unsigned int n, i;
  cin >> n;
  int *a = NULL;
  my_slightly_less_dumb_reallocation(&a, 0, n / 2);
  for (i = 0; i < n / 2; i++)
  	cin >> a[i];
  my_slightly_less_dumb_reallocation(&a, n / 2, n);
  for (; i < n; i++)
  	cin >> a[i];
  int sum = 0;
  for (i = 0; i < n; i++)
  	sum += a[i];
  cout << sum << endl;
  my_slightly_less_dumb_reallocation(&a, n, n / 2);
  my_slightly_less_dumb_reallocation(&a, n / 2, 0);
  my_slightly_less_dumb_reallocation(&a, 0, 0);
  return 0;
}
