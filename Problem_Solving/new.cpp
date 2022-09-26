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
    vector<int> a(n), c;
    for (auto &x : a) cin >> x;
    int l , r;
    if (n % 2 == 0) {
      l = 0, r = 1;
    }
    else {
      l = 1, r = 2;
      c.push_back(a[0]);
    }
    while (r < n) {
      c.push_back(min(a[l],a[r]));
      c.push_back(max(a[l],a[r]));
      l += 2, r += 2;
    }
    sort(all(a));
    if (c == a)
      cout << "YES\n";
    else 
      cout << "NO\n";
    
    

  }
  return 0;
}