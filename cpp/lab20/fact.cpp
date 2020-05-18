#include <iostream>


using namespace std;


int forward_fact(int n, int p)
{
  if (n < 2)
    return p;
  else
    return forward_fact(n-1, p*n);
}


int backward_fact(int n)
{
  if (n < 2)
    return 1;
  else
    return backward_fact(n-1) * n;
}


int main()
{
  int n = -1, choice = -1;
  cout << "Choose forward (0) or backward (1): ";
  cin >> choice;
  cout << "Enter n: ";
  cin >> n;
  if (choice == 0)
    cout << forward_fact(n, 1);
  else
    cout << backward_fact(n);
}
