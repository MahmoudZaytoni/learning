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
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      mp[x]++;
    }

    vector<int> v;
    for (auto it : mp)
      if (it.second >= k)
        v.push_back(it.first);
    
    if (v.size() == 0) {
      cout << -1 << "\n";
      continue;
    }
    int cnt = 0;
    int l = v[0], r = v[0], distance = 0;
    for (int i = 1; i < (int)v.size(); i++) {
      if (v[i] - v[i-1] == 1) {
        cnt++;
        if (cnt > distance) {
          l = v[i-cnt];
          r = v[i];
          distance = r - l;
        }
      } else {
          cnt = 0;
      }
    }
    cout << l << " " << r << "\n";
  }
  return 0;
}