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

vector<vector<int>> rotate(vector<vector<int>> v) {
  vector<vector<int>> ans = v;
  ans[0][0] = v[1][0];
  ans[0][1] = v[0][0];
  ans[1][0] = v[1][1];
  ans[1][1] = v[0][1];
  return ans;
}

bool Sorted(vector<vector<int>> v) {
  if (v[0][0] < v[0][1] && v[1][0] < v[1][1] && v[0][0] < v[1][0] && v[0][1] < v[1][1])
    return true;
  return false;
}
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
    vector<vector<int>> v(2, vector<int>(2));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
        cin >> v[i][j];
    }

    vector<vector<int>> a, b, c, d;
    a = v;
    b = rotate(a);
    c = rotate(b);
    d = rotate(c);
    if (Sorted(a) || Sorted(b) || Sorted(c) || Sorted(d))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}