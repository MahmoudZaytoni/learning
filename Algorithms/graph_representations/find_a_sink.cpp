#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

typedef vector<vector<int>> GRAPH;

int findSinkSlow(GRAPH &graph) {
    int nodes = (int)graph.size();
    int in_degree_must = nodes - 1;
    for (int i = 0; i < nodes; i++) {
        int cnt = 0;
        int j = 0;
        for (; j < nodes; j++) {
            if (graph[j][i] == 1)
                cnt++;
            else 
                continue;
        }
        if (cnt == in_degree_must)
            return i;
    }
    return -1;
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int nodes, edges;
        cin >> nodes >> edges;
        GRAPH graph(nodes, vector<int>(nodes,0));
        for (int e = 0; e < edges; e++) {
            int from, to; cin >> from >> to;
            graph[from][to] = 1;
        }
        cout << findSinkSlow(graph) << "\n";
    }
    return 0;
}
