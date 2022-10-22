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
    set<char> a;
    set<char, greater<char>> b;
    a.insert('a');
    b.insert('a');
    ll l1 = 1, l2 = 1;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      int d, k; cin >> d >> k;
      string str; cin >> str;
      if (d == 1) {
        a.insert(str.begin(), str.end());
        l1 += (1ll * k * sz(str));
      } else {
        b.insert(str.begin(), str.end());
        l2 += (1ll * k * sz(str));
      }
      bool ok = false, e = true;
      int j = 0;
      for (auto it1 = a.begin(), it2 = b.begin(); j < min(sz(a), sz(b)); it1++, it2++, j++) {
        if (*it1 < *it2) {
          ok = true;
          break;
        } else if (*it1 > *it2) {
          e = false;
          break;
        }
      }
      e &= (sz(a) == sz(b));
      if (e)
        ok |= (l1 < l2);
      cout << ((ok) ? "YES\n" : "NO\n");
    }

  }
  return 0;
}