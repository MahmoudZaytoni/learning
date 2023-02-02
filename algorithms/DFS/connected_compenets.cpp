#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from , int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void build_graph_from_edges(GRAPH &graph, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) 
        add_undirected_edge(graph, edges[i][0], edges[i][1]);
}

void dfs(GRAPH &graph, int node, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbour : graph[node]) 
        if (!visited[neighbour])
            dfs(graph,neighbour, visited);
}

int count_components(GRAPH &graph) {
    int nodes = graph.size();
    vector<bool> visited(nodes);

    int counter = 0;
    for (int src = 0; src < nodes; src++) {
       if (!visited[src]) {
            ++counter;
            dfs(graph, src, visited);
       }
    }
    return counter;
}

class Solution {
private:
    
public:
        
    
    int countComponents(int n, vector<vector<int>> &edges) {
        GRAPH graph(n);
        build_graph_from_edges(graph, edges);
        return count_components(graph);
    }
};