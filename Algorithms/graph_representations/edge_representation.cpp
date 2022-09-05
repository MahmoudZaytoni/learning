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

class edge {
  int from;
  int to;
  int weight;

public:
  edge(int from, int to, int cost) : from(from), to(to), weight(cost) {}

  bool operator < (const edge &e) const {
      return weight < e.weight;
  }

  void print() {
      cout << "Edge (" << from << " " << to << " " << weight << "\n";
  }

};

typedef vector<edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost) {
    graph.push_back({from,to,cost});
}

void print_adjecancy_matrix(GRAPH &graph) {
    for (int edge = 0; edge < (int)graph.size(); edge++) 
        graph[edge].print();
}

int main() 
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    GRAPH graph;
    for (int e = 0; e < edges; e++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_edge(graph, from , to, cost);
    }
    sort(all(graph));
    print_adjecancy_matrix(graph);
    return 0;
}
