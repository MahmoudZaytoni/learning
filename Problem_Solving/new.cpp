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
  //cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int,int> mp;
    for (auto &x : a) {
      cin >> x;
      mp[x]++;
    }
    int ans = 0;
    for (auto &x : b) cin >> x;
    int j = 0, i = 0;
    while (i < n && j < n) {
      if (mp[a[i]] == 0) {
        i++;
        continue;
      }
      if (a[i] != b[j]) {
        mp[b[j]]--;
        ans++;
        j++;
      } else {
        i++, j++;
      }
    }       
    cout << ans << "\n";
  }
  return 0;
}