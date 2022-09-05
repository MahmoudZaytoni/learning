
#include <iostream>
#include <queue>
#include <vector>
#define OO 1e9
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from ,int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void add_directed_edge(GRAPH &graph, int from ,int to) {
    graph[from].push_back(to);
}


bool bfs_cycle(GRAPH &graph, int start, vector<int> &len, vector<int> &parent) {
    queue<int> q;
    q.push(start);
    len[start] = 0;

    for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size()) {
        while (sz--) {
            int cur = q.front();
            q.pop();
            for (int neighbour : graph[cur]) {
                if (neighbour == parent[cur]) // fake cycle
                    continue;
                if (len[neighbour] == OO) {
                    q.push(neighbour);
                    len[neighbour] = level+1;
                    parent[neighbour] = cur;
                } else 
                    return true;
            }
        }
    }
    return false;
}

bool has_cycle(GRAPH &graph) {
    int nodes = graph.size();

    vector<int> len(nodes, OO);
    vector<int> parent(nodes, -1);

    for (int i = 0; i < nodes; i++) { 
        if (len[i] == OO && bfs_cycle(graph, i, len, parent))
            return true;
    }
    return false;
}

int main() 
{
    int t; cin >> t;
    while (t--) {
        int nodes, edges; cin >> nodes >> edges;
        GRAPH graph(nodes);
        for (int e = 0; e < edges; e++) {
            int from, to; cin >> from >> to;
            add_undirected_edge(graph, from, to);
        }
        cout << has_cycle(graph) << "\n";
    } 
}
