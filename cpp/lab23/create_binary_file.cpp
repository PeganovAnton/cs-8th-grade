#include <stdint.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;


int main()
{
  int32_t n;
  int64_t *arr;
  ofstream ofs;
  const int32_t size = 256;
  const char fn[size] = "array.bin", type[size] = "int64_t";
  cin >> n;
  arr = new int64_t[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  ofs.open(fn, fstream::binary);
  ofs.write((char*)type, sizeof(type[0]) * size);
  ofs.write((char*)&n, sizeof(int32_t));
  ofs.write((char*)arr, sizeof(int64_t) * n);
  ofs.close();
  delete[] arr;
}
