#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> GRAPH;



vector<int> topsort(const GRAPH &adjList) {
    int sz = adjList.size();
    vector<int> ordering;
    vector<int> indegree(sz);
    for (int node = 0; node < sz; node++) 
        for (int neighbour : adjList[node])
            indegree[neighbour]++;

    queue<int> ready;
    for (int node = 0; node < sz; node++) 
        if (indegree[node] == 0)
            ready.push(node);
        
    while (!ready.empty()) {
        int cur = ready.front();
        ready.pop();

        ordering.push_back(cur);
        for (int neighbour : adjList[cur])
            if (--indegree[neighbour] == 0)
                ready.push(neighbour);
    }

    if (ordering.size() != sz)
        ordering.clear();

    return ordering;
}



int main()
{

    int nodes, edges; cin >> nodes >> edges;

    GRAPH graph(nodes + 1);
    for (int e = 0; e < edges; e++) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
    }

    vector<int> topSort = topsort(graph);
    for (auto n : topSort) 
        cout << n << " ";
    cout << "\n";
    return 0;
}