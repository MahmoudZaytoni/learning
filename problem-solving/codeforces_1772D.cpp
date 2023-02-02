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

int main() 
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    ll n; cin >> n;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    ll mnx = 1e9+5, mx = 0;
    for (int i = 0; i < n-1; i++) {
      ll x = v[i];
      ll y = v[i+1];

      if (x < y)
        mnx = min(mnx, (x + y) / 2);
      else if (x > y){
        mx = max(mx, (x + y + 1) / 2);
      }
    }

    if (mnx >= mx)
      cout << (mx + mnx) / 2 << "\n";
    else
      cout << -1 << "\n";
  
  }
  return 0;
}