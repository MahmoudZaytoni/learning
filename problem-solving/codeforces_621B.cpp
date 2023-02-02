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
  
int dx[4] = {1,-1,1,-1};
int dy[4] = {1,-1,-1,1};
  
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  map<pair<int,int>, int> mp;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    mp[{x,y}]++;
  }
  ll ans = 0;
  for (auto item : mp) {
    if (item.second == 1) {
      pair<int,int> point = make_pair(item.first.first, item.first.second);
      ll cnt = 1;
      for (int d = 0; d < 4; d++) {
        int x = point.first + dx[d];
        int y = point.second + dy[d];
        while (x > 0 && x <= 2000 && y > 0 && y <= 2000) {
          if (mp[{x,y}]) {
            cnt++;
            mp[{x,y}]++;
          }
          x += dx[d];
          y += dy[d];
        }
      }
      ans += (cnt * (cnt-1)) / 2;
    }
  }
  cout << ans << "\n";
  return 0;
}