#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;





typedef vector<vector<int>> GRAPH; // adj list representation

void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}


bool has_cycle(GRAPH &graph, vector<bool> &visited, int parent, int node) {
    visited[node] = 1;
    for (auto &neighboor : graph[node]) {
        if (neighboor == parent)
            continue;
        if (visited[neighboor])
            return true;
        if (has_cycle(graph, visited, node, neighboor))
            return true;
    }
    return false;
}

int main() 
{
    int t; cin >> t;
    while (t--) {
        int nodes, edges;
        cin >> nodes >> edges;

        GRAPH graph(nodes);
        for (int e = 0; e < edges; e++) {
            int from, to;
            cin >> from >> to;
            add_undirected_edge(graph, from , to);
        }
        
        vector<bool> visited(nodes);
        cout << has_cycle(graph, visited, -1, 0);
    }


    return 0;
}