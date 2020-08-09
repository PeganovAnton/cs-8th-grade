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


int lomuto_partition(int *a, int lo, int hi)
{
  int pivot = a[hi];
  int left = lo;
  while(a[left] < pivot)
    ++left;
  for(int right=left+1; right<hi; ++right){
    if (a[right] < pivot) {
      swap(a, left, right);
      ++left;
    }
  }
  swap(a, left, hi);
  return left;
}


// lo (lowest) -- index of leftmost element of sorted subarray
// hi (highest) -- index of rightmost element of sorted subarray
void lomuto_quick_sort(int *a, int lo, int hi)
{
  if (hi - lo < 1)
    return;
  int p = lomuto_partition(a, lo, hi);
  lomuto_quick_sort(a, lo, p-1);
  lomuto_quick_sort(a, p+1, hi);
}


int main()
{
  int a[10] = {2, 1, 6, 3, 10, 5, 4, 8, 7, 9};
  lomuto_quick_sort(a, 0, 9);
  print_array(a, 10);
}

