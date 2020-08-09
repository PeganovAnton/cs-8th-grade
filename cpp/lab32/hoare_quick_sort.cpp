#include <iostream>


using namespace std;


void print_array(int *a, int len)
{
   for(int i=0; i<len; ++i)
     cout << a[i] << ' ';
   cout << endl;
}


void swap(int *a, int i, int j)
{
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}


int hoare_partition(int *a, int lo, int hi)
{
  int left = lo - 1;
  int right = hi + 1;
  int pivot = a[lo];
  while (true){
    ++left;
    while(a[left] < pivot)
      ++left;
    --right;
    while(a[right] > pivot)
      --right;
    if (left >= right)
      return right;
    swap(a, left, right);
  }
}


// lo (lowest) -- index of leftmost element of sorted subarray
// hi (highest) -- index of rightmost element of sorted subarray
void hoare_quick_sort(int *a, int lo, int hi)
{
  if (hi - lo < 1)
    return;
  print_array(a, 10);
  int p = hoare_partition(a, lo, hi);
  cout << p << endl;
  hoare_quick_sort(a, lo, p);  // FIXME
  hoare_quick_sort(a, p+1, hi);  // FIXME
}


int main()
{
  int a[10] = {2, 1, 6, 3, 10, 5, 4, 8, 7, 9};
  hoare_quick_sort(a, 0, 9);
  print_array(a, 10);
}

