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

void add_directed(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}

void print_chain(GRAPH graph, int from) {
    cout << from << " ";
    if (graph[from].size() == 0)
        return;
    print_chain(graph, graph[from][0]);
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int nodes, edges;
        cin >> nodes >> edges;
        GRAPH graph(nodes);
        for (int e = 0; e < edges; e++) {
            int from, to; cin >> from >> to;
            add_directed(graph, from, to);        
        }

        int q; cin >> q;
        while (q--) {
           int node; cin >> node;
           print_chain(graph,node);
           cout << "\n";
        }
    }
    return 0;
}

/*
6 5
4 1
1 2
5 3
0 5
3 4
4
0
3
1
2
*/

