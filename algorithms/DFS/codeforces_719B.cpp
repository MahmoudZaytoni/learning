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

typedef vector<vector<int>> GRAPH;

int dfs(GRAPH &graph, vector<int> &visited, int node, int &edges) {
  if (visited[node])
    return 0;
  visited[node] = 1;
  int component = 1;
  edges += graph[node].size();
  for (int neighbour : graph[node]) {
    if (!visited[neighbour])
      component += dfs(graph, visited, neighbour, edges);
  }
  return component;
}

bool possible(int edges, int component) {
  return ll(ll(component) * (ll(component) - 1)) / 2 == ll(edges) / 2;
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  s:while (t--) {
    int n, m; cin >> n >> m;
    GRAPH graph(n + 1);
    for (int i = 0; i < m; i++) {
      int from, to; cin >> from >> to;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    vector<int> visited(n + 1);
    for (int node = 1; node <= n; node++) {
      if (!visited[node]) {
        int edges = 0;
        int component = dfs(graph, visited, node, edges);
        // cout << "debug: " << component <<  "edges: " << edges << "\n";
        if (!possible(edges, component)) {
          cout << "NO\n";
          goto s;
        }
      }
    }
    cout << "YES\n";
  }
  return 0;
}