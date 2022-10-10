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

bool can(vector<pair<ll,ll>> &v, ll mid, int  d) {
  ll sum = 0, i = 0, j = 0, n = v.size();
  while (j < n && i < n) {
    if (v[j].first - v[i].first < d)
      sum += v[j++].second;
    if (sum >= mid)
      return 1;
    if (v[j].first - v[i].first >= d)
      sum -= v[i++].second;
  }
  return 0;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d; cin >> n >> d;
  vector<pair<ll,ll>> v(n);
  ll st = 0,en = 0;
  for (auto &it : v) { 
    cin >> it.first >> it.second;
    en += it.second;
  }
  sort(all(v));
  ll ans = 0;
  while (st <= en) {
    ll mid = st + (en - st) / 2;
    if (can(v, mid, d)) {
      ans = mid;
      st = mid + 1;
    } else 
      en = mid - 1; 
  }
  cout << ans << "\n";
  return 0;
}