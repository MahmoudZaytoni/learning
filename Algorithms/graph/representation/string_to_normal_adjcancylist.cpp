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

class ObjectMapper {
    map<string,int> str_to_id;
    map<int,string> id_to_str;
public:
    int getId(string &str) {
        if (str_to_id.count(str))
            return str_to_id[str];

        int id = str_to_id.size();
        str_to_id[str] = id;
        id_to_str[id] = str;
        return id;
    }

    string getStr(int id) {
        return id_to_str[id];
    }
};

struct edge {
  int to;
  int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost) {
    graph[from].push_back({to,cost});
}

void add_undirected_edge(GRAPH &graph, int from, int to, int cost) {
   graph[from].push_back({to, cost});
   graph[to].push_back({from, cost});
}

void print_adjacency_matrix(GRAPH &graph, ObjectMapper &mapper) {
    int nodes = graph.size();
    for (int from = 0; from < nodes; from++) {
        cout << "Node " << mapper.getStr(from) << " has nighbors: \n";
        for (int edge = 0; edge < (int)graph[from].size(); edge++) {
            cout << "\tTo " << mapper.getStr(graph[from][edge].to)
                << " cost " << graph[from][edge].cost << "\n";
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);
    ObjectMapper mapper;

    while (edges--) {
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        int from_idx = mapper.getId(from);
        int to_idx = mapper.getId(to);
        add_directed_edge(graph,from_idx, to_idx, cost);
    }
    print_adjacency_matrix(graph,mapper);
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
