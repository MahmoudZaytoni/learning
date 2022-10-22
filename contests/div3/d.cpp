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

int solve(int l, int r, vector<int> &v) {
  if (r-l == 1)
    return 0;
  
  int mid = l + (r - l) / 2;
  int mx_l = *max_element(v.begin() + l, v.begin() + mid);
  int mx_r = *max_element(v.begin() + mid, v.begin() + r);

  int ans = 0;
  if (mx_l > mx_r) {
    ans++;
    for (int i = 0; i < (mid - l); i++) 
      swap(v[i+l], v[i+mid]);
  }
  return solve(l,mid,v) + solve(mid, r, v) + ans;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int ans = solve(0, n, v);
    if(is_sorted(all(v)))
      cout << ans << "\n";
    else 
      cout << -1 << "\n";
  }
  return 0;
}