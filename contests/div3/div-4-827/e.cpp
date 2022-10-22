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

ll bs(vector<ll> &v, ll h) {
  ll l = 0, r = sz(v) - 1, ans = -1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (v[mid] <= h) {
      ans = mid, l = mid + 1;
    }else
      r = mid - 1;
  }
  return ans;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t = 1;
  cin >> t;
  while (t--) {
    ll n, q; cin >> n >> q;
    vector<ll> stairs(n);
    for (auto &x : stairs) cin >> x;
    vector<ll> v(n);
    v[0] = stairs[0];
    for (ll i = 1; i < n; i++) {
      if (stairs[i] > v[i-1])
        v[i] = stairs[i];
      else {
        v[i] = v[i-1];
      }
    }
    for (ll i = 1; i < n; i++) {
      stairs[i] += stairs[i-1];
    }
    for (ll i = 0; i < q; i++) {
      ll h; cin >> h;
      ll idx = bs(v, h);
      if (idx == -1 || h == 0)
        cout << 0 << " ";
      else if (idx >= n)
        cout << stairs.back() << " ";
      else {
        cout << stairs[idx] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}