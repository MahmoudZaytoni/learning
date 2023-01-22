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


int n, a, b;
vector<vector<pair<int,int>>> graph;
set<int> st;


void dfs(int cur, int par, int x) {
  if (cur == b) return;
  st.insert(x);
  for (auto e : graph[cur]) {
    int to = e.first, w = e.second;
    if (par == to)continue;
    dfs(to, cur, x ^ w);
  }
}

bool dfs2(int cur, int par, int x) {
  if (cur != b && st.count(x))
    return true;
  for (auto e : graph[cur]) {
    int to = e.first, w = e.second;
    if (par == to)
      continue;
    if (dfs2(to, cur, w ^ x)) return true;
  }
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
    st.clear();
    cin >> n >> a >> b;
    a--, b--;
    graph.clear();
    graph.resize(n);
    for (int i = 1 ; i< n; i++) {
      int from, to, w;
      cin >> from >> to >> w;
      from--, to--;
      graph[from].push_back(make_pair(to,w));
      graph[to].push_back(make_pair(from, w));
    }

    dfs(a, -1, 0);
    if (dfs2(b, -1, 0))
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
  return 0;
}