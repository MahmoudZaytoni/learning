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

void add_directed_edge(GRAPH &graph,int from, int to) {
    graph[from].push_back(to);
}

void add_undirected_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void print_adjaceny_matrix(GRAPH &graph) {
    int nodes = (int)graph.size();
    for (int from = 0; from < nodes; from++) {
        cout << "Nodes " << from << " has neighbors: ";
        for (int edge = 0; edge < graph[from].size(); edge++) 
            cout << graph[from][edge] << " ";
        cout << "\n";
    }
}

bool isValid(int nr, int nc, int rows, int cols) {
    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
        return false;
    return true;
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rows, cols;
    cin >> rows >> cols;

    GRAPH graph(rows * cols);


    int nr, nc, to;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int from = r * cols + c;

            nr = r + 1, nc = c, to = nr * cols + nc;
            if (isValid(nr, nc, rows, cols))
                add_directed_edge(graph, from, to);
 
            nr = r - 1, nc = c, to = nr * cols + nc;
            if (isValid(nr, nc, rows, cols))
                add_directed_edge(graph, from, to);
 
            nr = r, nc = c - 1, to = nr * cols + nc;
            if (isValid(nr, nc, rows, cols))
                add_directed_edge(graph, from, to);
 
            nr = r, nc = c + 1, to = nr * cols + nc;
            if (isValid(nr, nc, rows, cols))
                add_directed_edge(graph, from, to);
        }
    }

    print_adjaceny_matrix(graph);

    return 0;
}
