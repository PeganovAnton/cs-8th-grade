#include <iostream>
#include <vector>


using namespace std;


int sol_iter(vector<int>& cost)
{
  int sum_n_m_1 = 0, sum_n_m_2 = 0, tmp = 0;
  if (cost.size() < 3)
    return cost.back();
  else {
    sum_n_m_2 = cost[0];
    sum_n_m_1 = cost[1];
    for(int i=2; i<cost.size(); i++) {
      tmp = sum_n_m_1;
      if (sum_n_m_1 > sum_n_m_2)
        sum_n_m_1 = sum_n_m_2 + cost[i];
      else
        sum_n_m_1 += cost[i];
      sum_n_m_2 = tmp;
    }
  }
  return sum_n_m_1;
}


int sol(vector<int>& cost)
{
  /*for(int i=0; i < cost.size(); i++)
    cout << cost[i] << ' ';
  cout << endl;*/
  int sum_n_m_1 = 0, sum_n_m_2 = 0;
  if (cost.size() == 1)
    return cost[0];
  else if (cost.size() == 2)
    return cost[1];
  else {
    vector<int> *cost_n_m_1 = new vector<int>();
    *cost_n_m_1 = cost;
    cost_n_m_1->pop_back();
    vector<int> *cost_n_m_2 = new vector<int>();
    *cost_n_m_2 = *cost_n_m_1;
    cost_n_m_2->pop_back();
    sum_n_m_1 = sol(*cost_n_m_1);
    sum_n_m_2 = sol(*cost_n_m_2);
    // cout << sum_n_m_1 << ' ' << sum_n_m_2 << endl;
    delete cost_n_m_1;
    delete cost_n_m_2;
    if (sum_n_m_1 > sum_n_m_2)
      return sum_n_m_2 + cost.back();
    else
      return sum_n_m_1 + cost.back();
  }
}


int main()
{
  vector<int> cost;
  int n, a;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    cost.push_back(a);
  }
  cost.push_back(0);
  cout << sol_iter(cost) << endl; 
}
