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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), a;
    for (auto &x : v) cin >> x;
    sort(all(v), greater<ll>());

    map<ll, bool> mp;

    for (ll i = 1; i <= 1e16; i *= k) 
      a.push_back(i);

    sort(all(a), greater<ll>());

    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < sz(a); j++) {
        if (v[i] >= a[j] && mp[a[j]] != 1) {
          v[i] -= a[j];
          mp[a[j]] = true;
        }
      }
      if (v[i] != 0) {
        ok = false;
        break;
      }
    }
    cout << ((ok) ? "YES\n" : "NO\n");
  }
  return 0;
}