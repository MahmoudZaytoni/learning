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


class Edge {
public:
    string to;
    int weight;
    Edge(string to, int cost) : to(to), weight(cost) {}

    bool operator < (const Edge &e) const {
        if (to != e.to)
            return to < e.to;
        return weight < e.weight;
    }
};

typedef map<string,multiset<Edge>> GRAPH;

void add_directed_edge(GRAPH &graph,string from, string to, int cost) {
    graph[from].insert({to, cost});
}

void print_adjacency_matrix(GRAPH &graph) {
    for (auto node : graph) {
        cout << "Flight from " << node.first << ": \n";
        for (const Edge &edge : node.second)
            cout << "\tTo " << edge.to << " with cost " << edge.weight << "\n";
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph;

    while (edges--) {
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        add_directed_edge(graph,from,to,cost);
    }
    print_adjacency_matrix(graph);

    return 0;
}




/* 
5 9
California Texas 30
California Texas 10
Florida California 70
California Florida 75
NewYork California 35
Pennsylvania Florida 18
Pennsylvania Florida 28
California Texas 35
California Pennsylvania 37
*/
