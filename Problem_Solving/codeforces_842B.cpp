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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int cnt = 0;
    int idx = 1;
    for (int i = 0; i < n; i++) {
      if (v[i] == idx)
        idx++;
      else {
        cnt++;
      }
    }

    cout << (cnt + k - 1) / k << "\t";
    if (cnt % k == 0)
      cout << cnt / k << "\n";
    else cout << cnt / k + 1 << "\n";

  }
  return 0;
}