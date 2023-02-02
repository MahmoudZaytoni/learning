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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> v(n), pre(n);
    for (auto &x : v) cin >> x;
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
      pre[i] = pre[i-1] + v[i];
    
    ll ans = 0;
    map<ll, ll> freq;
    ll mx_freq = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        if (zero) ans += mx_freq;
        else ans += freq[0];
        zero = true;
        freq.clear();
        mx_freq = 0;
      }
      mx_freq = max(mx_freq, ++freq[pre[i]]);
    }
    
    if (zero) ans += mx_freq;
    else ans += freq[0];
    cout << ans << "\n";

  }
  return 0;
}