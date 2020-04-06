#include <iostream>


using namespace std;


int bin_search_rec(int v, int *arr, int start, int end) {
  if (end - start < 2)
    if (arr[start] == v)
      return start;
    else
      return -1;
  else if (arr[(start + end) / 2] > v)
    return bin_search_rec(v, arr, start, (start + end) / 2);
  else
    return bin_search_rec(v, arr, (start + end) / 2, end);
}


int main()
{
  int size = -1, value = 0;
  int *arr = 0;
  cin >> size;
  arr = new int[size];
  for(int i=0; i<size; i++){
    cin >> arr[i];
  }
  cin >> value;
  cout << bin_search_rec(value, arr, 0, size) << endl;
  delete[] arr;
}
