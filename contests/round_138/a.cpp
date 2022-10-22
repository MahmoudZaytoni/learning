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
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
    }
    if (m < n) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}