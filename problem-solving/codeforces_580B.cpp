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
  int n, d; cin >> n >> d;
  vector<pair<ll,ll>> v(n);
  for (auto &it : v) cin >> it.first >> it.second;
  sort(all(v));
  ll mx = 0, i = 0, j = 1, sum = v[0].second;
  for (int i = 0; i < n; i++) {
    while (j < n && v[j].first - v[i].first < d) {
      sum += v[j].second;
      j++;
    }
    mx = max(mx, sum);
    sum -= v[i].second;
    if (j == n)
      break;
  }
  cout << mx << "\n";
  return 0;
}