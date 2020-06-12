#include <stdint.h>
#include <fstream>
#include <iostream>


using namespace std;


int main()
{
  const int size = 256;
  const char fn[size] = "array.bin";
  char type[size];

  int64_t *arr;
  int32_t n;

  ifstream ifs;
  ifs.open(fn, ios_base::binary);
  ifs.read((char*)type, size * sizeof(char));
  cout << "type: " << type << endl;
  ifs.read((char*)&n, sizeof(n));
  cout << "size of array: " << n << endl;
  arr = new int64_t[n];
  ifs.read((char*)arr, sizeof(int64_t) *n);
  for(int i=0; i<n; i++)
    cout << arr[i] << ' ';
  cout << endl;
  ifs.close();
  delete[] arr;
}
