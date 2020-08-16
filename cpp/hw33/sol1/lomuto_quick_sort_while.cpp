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


int lomuto_search(int *a, int lo, int hi, int k)
{
        while(hi - lo < 1)
            return a[k+1];
        int p = lomuto_partition(a, lo, hi);
        if(k < p)
            hi = p - 1;
        if(k > p)
            lo = p + 1;
}


int main()
{
  int a[10] = {2, 1, 6, 3, 10, 5, 4, 8, 7, 9};
  int k;
  cin >> k;
  cout << lomuto_search(a, 0, 9, k) << endl;
  print_array(a, 10);
  return 0;
}

