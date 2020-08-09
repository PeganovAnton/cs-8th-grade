#include <iostream>


using namespace std;


void print_array(int *a, int len)
{
   for(int i=0; i<len; ++i)
     cout << a[i] << ' ';
   cout << endl;
}


void merge(int *a, int *buffer, int left, int middle, int right)
{
  int first = left;
  int second = middle;
  int merged = left;
  cout << left << ' ' << middle << ' ' << right << endl;
  while(merged < right){
    if(second >= right) {
      buffer[merged] = a[first];
      ++first;
    } else if (first >= middle) {
      buffer[merged] = a[second];
      ++second;
    } else if (a[first] <= a[second]) {
      buffer[merged] = a[first];
      ++first;
    } else {
      buffer[merged] = a[second];
      ++second;
    }
    ++merged;
  }
}


void copy_array(int *a, int *b, int n)
{
  for(int i=0; i<n; ++i)
    b[i] = a[i];
}


void merge_sort(int *a, int n)
{
  int *buffer = new int[n];
  int size = 1;
  while(size < n) {
    for(int i=0; i<n; i+=2*size){
      if (i+size < n) {
        merge(a, buffer, i, i+size, i+2*size>n ? n : i+2*size);
      }
    }
    copy_array(buffer, a, n);
    size *= 2;
  }
  delete[] buffer;
}


int main()
{
  int a[10] = {2, 1, 6, 3, 10, 5, 4, 8, 7, 9};
  merge_sort(a, 10);
  print_array(a, 10);
}

