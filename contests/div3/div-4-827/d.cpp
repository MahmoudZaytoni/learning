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
  multimap<int,int> mp;
  for (int i = 1; i <= 1000; i++) {
    for (int j = i; j <= 1000; j++) {
      if (__gcd(i,j) == 1)
        mp.insert(make_pair(i,j));
    }
  }
  cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int,int> mp2;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      mp2[x] = i;
    }

    int ans = -1;
    for (auto &pair : mp) {
      if (mp2.count(pair.first) != 0 && mp2.count(pair.second) != 0)
        ans = max(ans, mp2[pair.first] + mp2[pair.second]);
    }
    cout << ans << "\n";
  }
  return 0;
}