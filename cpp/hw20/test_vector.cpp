#include <iostream>
#include <vector>


using namespace std;


void sqr(vector<int> v)
{
  for(int i=0; i<v.size(); i++)
    v[i] *= v[i];
}


int main()
{
  vector<int> v;
  int n, tmp;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> tmp;
    v.push_back(tmp);
  }
  sqr(v);
  for(int i=0; i<n; i++)
    cout << v[i] << ' ';
  cout << endl;
}
