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
    vector<int> a(n);
    vector<pair<int,int>> b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      a[i] = x;
      sum += x;
    }
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      b[i] = make_pair(x, i);
    }

    sort(all(b));

    for (int i = 0; i < n - 1; i++) {
      sum += b[i].first;
    }
    cout << sum << "\n";
  }
  return 0;
}