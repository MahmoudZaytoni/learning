#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
using namespace std;
typedef long long ll;

typedef vector<unordered_set<int>> GRAPH;

void add_edge(GRAPH &graph, int from, int to) {
    graph[from].insert(to);
}

void print_adjecancy_matrix(GRAPH &graph) {
    int nodes = graph.size();
    for (int from = 0; from < nodes; from++) {
        cout << "Node" << from << "has neighbors: ";
        for (auto to : graph[from]) 
            cout << to << " ";
        cout << endl;
    }
}

int main() 
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    GRAPH graph(nodes);
    for (int e = 0; e < edges; e++) {
        int from, to, cost;
        cin >> from >> to;
        add_edge(graph, from , to);
    }
    print_adjecancy_matrix(graph);
    return 0;
}

/*
6 7
2 1
2 5
2 0
2 3
0 5
1 4
5 4
*/
