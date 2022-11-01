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
#ifndef ONLINE_JUDGE
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    string str; cin >> str;
    str.insert(str.begin(), ' ');
    int ans = 0;
    if (n % 2 == 0) {
      for (int i = 2; i < sz(str); i += 2)
        if ((str[i] - '0') % 2 == 0) {
          ans = 2;
          break;
        }
      if (ans == 0)
        ans = 1;
    } else {
      for (int i = 1; i < sz(str); i+= 2)
        if ((str[i] - '0') % 2 != 0) {
          ans = 1;
          break;
        }
      if (ans == 0)
        ans = 2;
    }
    cout << ans << "\n";
  }
  return 0;
}