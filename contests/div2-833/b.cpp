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
    ll ans = 0;
    string s; cin >> s;
    for (ll i = 0; i < s.size(); i++) {
      vector<ll> freq(10);
      ll distinct = 0, max_freq = 0;
      for (ll j = i; j < s.size() && j < (i + 100); j++) {
        freq[s[j] - '0']++;
        max_freq = max(max_freq, freq[s[j]-'0']);
        if (freq[s[j] - '0'] == 1)
          distinct++;
        if (distinct >= max_freq)
          ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}