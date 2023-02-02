#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <cstring>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;


int n, l, r, x;
vector<int> v;
const int MAX = 15 + 1;
int dp[MAX][MAX];
int all_subsets(int i, int have, int sum, int mx, int mn) {
  if (i == n)
    return (sum >= l && sum <= r && have > 1 && mx - mn >= x);
  
  int &ret = dp[i][have];
  if (ret != -1 && have >= 2)
    return ret;
  int choice1 = all_subsets(i+1, have, sum, mx, mn); // leave it
  int choice2 = all_subsets(i+1, have + 1, sum + v[i], max(v[i], mx), min(v[i], mn)); // pick it
  return ret = (choice1 + choice2);
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    cin >> n >> l >> r >> x;
    v = vector<int>(n);
    for (auto &x : v) cin >> x;
    cout << all_subsets(0, 0, 0, 0, INT_MAX);
  }
  return 0;
}