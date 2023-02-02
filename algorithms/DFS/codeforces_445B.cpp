#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

typedef vector<vector<int>> GRAPH;

int dfs(GRAPH &graph, vector<bool> &visited, int node) {

  if (visited[node])
    return 0;

  visited[node] = 1;

  int items = 1;
  for (auto neighbour : graph[node])
    items += dfs(graph, visited, neighbour);
  return items;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    GRAPH graph(n);
    for (int i = 0; i < m; i++) {
      int from, to; cin >> from >> to;
      from--, to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    vector<bool> visited(n);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
      int component = 0;
      if (!visited[i]) {
        component = dfs(graph,visited,i); 
        ans *= (1ll << (component-1));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}