#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;


int n;
vector<int> v;
const int MAX = 1000;
int memory[MAX][MAX];
bool subset_sum(int idx, int target) {
  if (target < 0)
    return false;

  if (target == 0)
    return true;
  
  if (idx == (int)v.size())
    return false;  // can't find subset

  auto &ret = memory[idx][target];
  if (ret != -1)
    return ret;
  
  if (subset_sum(idx + 1, target))
    return ret = true;
  
  return ret = subset_sum(idx + 1, target - v[idx]);
}

bool can_subset_sum(int idx, int target) {
  if (idx == (int)v.size()) {
    if (target == 0)
      return true;
    return false;
  }

  if (target < 0)
    return false;
  
  auto &ret = memory[idx][target];
  if (ret != -1)
    return ret;

  bool choice1 = can_subset_sum(idx + 1, target);
  if (choice1)
    return ret = true;
  
  bool choice2 = can_subset_sum(idx + 1, target - v[idx]);
  if (choice2)
    return ret = true;
  
  return ret = choice1 || choice2;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    int n; cin >> n;
    memset(memory, -1, sizeof(memory));
    v = vector<int>{3, 12, 4, 12, 5, 2};
    cout << subset_sum(0, n) << "\n";
    memset(memory, -1, sizeof(memory));
    cout << can_subset_sum(0, n);
    cout << "\n";
  }
  return 0;
}