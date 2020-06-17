#include <iostream>
#include <string>


using namespace std;


template <typename T>
T getMax(T a, T b)
{
  if (a > b)
    return a;
  else 
    return b;
}


template <class T1, typename T2>
class MyPair
{
  public:
    T1 first;
    T2 second;
    
    void print()
    {
       cout << "{" << first << ", " << second << "}" << endl;
    }
};


int main()
{
  int ai, bi;
  double ad, bd;
  string as, bs;
  cin >> ai >> bi;
  cout << getMax<int>(ai, bi) << endl;
  cin >> ad >> bd;
  cout << getMax<double>(ad, bd) << endl;
  cin >> as >> bs;
  cout << getMax<string>(as, bs) << endl;
  MyPair<string, int> mp;
  mp.first = "foo";
  mp.second = 10;
  mp.print();
}
