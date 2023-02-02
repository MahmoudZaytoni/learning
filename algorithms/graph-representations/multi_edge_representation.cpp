
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


typedef vector<vector<vector<int>>> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost) {
    graph[from][to].push_back(cost);
}

void print_adjecancy_matrix(GRAPH &graph) {
    int nodes = graph.size();
    for (int from = 0; from < nodes; from++) {
        for (int to = 0; to < nodes; to++) {
            for (int weight : graph[from][to]) {
                cout << "From " << from << " to " << to
                    << " the cost is " << weight << "\n";
            }
        }
    }
}

int main() 
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    GRAPH graph(nodes, vector<vector<int>>(nodes));
    for (int e = 0; e < edges; e++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_edge(graph, from , to, cost);
    }
    print_adjecancy_matrix(graph);
    return 0;
}

/*
 5 10
 0 1 10
 1 2 7
 0 1 7
 2 3 9
 2 3 15
 3 4 50
 0 4 52
 0 4 30
 2 4 36
 4 0 150
 */
