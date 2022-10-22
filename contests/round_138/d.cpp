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

bool valid(int k) {
  vector<int> a = v;
  int l = 0, r = n - 1;
  for (int stage = k; stage >= 1; stage--) {
    while (r >= 0 && a[r] > stage)
      r--;
    if (r < 0)
      return 0;
    
    a[l++] += a[r];
    r--;
  }
  return 1;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    v = vector<int>(n);
    for (auto &x : v) cin >> x;
    sort(all(v));
    int ans = 0;
    for (int i = 1; i <= 100; i++)
      if (valid(i))
        ans = i;
    cout << ans << "\n";
  }
  return 0;
}