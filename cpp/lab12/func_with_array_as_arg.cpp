#include <iostream>


using namespace std;


int read_dyn_array(int **arr, int *n)
{
  int size;
  cout << "Enter size of an array\n";
  cin >> *n;
  size = *n;
  *arr = new int[size];
  cout << "Enter array of size " << size << endl;
  for(int i=0; i<size; i++)
    cin >> (*arr)[i];
}


int read_fixed_len_array(int arr[], int n)
{
  cout << "Enter array of size " << n << ":\n";
  for(int i=0; i<n; i++)
    cin >> arr[i];
}


int print_array_reverse(int *arr, int n)
{
  for(int i=0; i<n; i++)
    cout << arr[n-1-i] << ' ';
  cout << endl;
}


int main()
{
  int **p, *arr1, arr2[4] = {-1, -2, -3, -4}, n;
  read_dyn_array(&arr1, &n);
  print_array_reverse(arr1, n);
  read_fixed_len_array(arr2, 4);
  print_array_reverse(arr2, 4);
}
