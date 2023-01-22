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

int res = 0;
vector<vector<int>> tree;
vector<bool> vis;
string s; 
pair<int,int> dfs(int u) {
  int b = 0, w = 0;
  vis[u] = true;
  for (auto &node : tree[u]) {
    if (vis[node]) continue;
    auto x = dfs(node);
    b += x.first;
    w += x.second;
  }

  if (s[u] == 'B')
    b++;
  else 
    w++;
  if (b == w)
    res++;
  return {b, w};
}
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    res = 0;
    int n; cin >> n;
    tree = vector<vector<int>> (n, vector<int>(0));
    for (int i = 1; i < n; i++) {
      int x; cin >> x;
      x--;
      tree[x].push_back(i);
    }
    cin >> s;
    vis = vector<bool> (n);
    dfs(0);
    cout << res  << "\n";
  }
  return 0;
}