#include <iostream>


using namespace std;


void shift_cyclically(int *arr, int size, int shift)
{
  shift %= size;
  shift = (shift + size) % size;
  int *save = new int[shift];
  for(int i=0; i<shift; i++)
    save[i] = arr[size-shift+i];
  for(int i=0; i<size-shift; i++)
    arr[size-1-i] = arr[size-shift-1-i];
  for(int i=0; i<shift; i++)
    arr[i] = save[i];
  delete[] save; 
}


int main()
{
  int n, shift;
  cin >> n;
  cin >> shift;
  int *arr = new int[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  shift_cyclically(arr, n, shift);
  for(int i=0; i<n; i++)
    cout << arr[i] << ' ';
  cout << endl;
  delete[] arr;
}
