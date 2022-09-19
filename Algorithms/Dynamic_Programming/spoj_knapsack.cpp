// https://www.spoj.com/problems/KNAPSACK/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

const int MAX = 2000 + 1;
int memory[MAX][MAX];
int n, s;
vector<int> weight, value;

int knapsack(int idx, int remains) {
  if (idx == n)
    return 0;

  auto &ret = memory[idx][remains];
  if (ret != -1)
    return ret;
  int choice1 = knapsack(idx + 1, remains);
  int choice2 = 0;

  if (remains >= weight[idx]) // can pick it
    choice2 = value[idx] + knapsack(idx + 1, remains - weight[idx]);
  
  return ret = max(choice1, choice2);
}



int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> n;

  weight = vector<int>(n);
  value = vector<int>(n);

  memset(memory, -1, sizeof(memory));

  for (int i = 0; i < n; i++) 
    cin >> weight[i] >> value[i];
  
  cout << knapsack(0, s);
  return 0;
}