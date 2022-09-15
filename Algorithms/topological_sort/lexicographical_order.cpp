#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int>> GRAPH;

vector<int> lexicographical_order_v1(GRAPH &adjList) {
    int sz = adjList.size();
    vector<int> indegree(adjList.size());
    vector<int> ordering;

    for (int node = 0; node < adjList.size(); node++) 
        for (int neighbour : adjList[node])
            indegree[neighbour]++;
    
    vector<int> ready;
    for (int node = 0; node < sz; node++) 
        if (indegree[node] == 0)
            ready.push_back(node);
    
    sort(ready.begin(), ready.end(), greater<int>());
    while (!ready.empty()) {
        int cur = ready.back();
        ready.pop_back();

        ordering.push_back(cur);
        for (int neighbour : adjList[cur])
            if (--indegree[neighbour] == 0)
                ready.push_back(neighbour);
        sort(ready.begin(), ready.end(), greater<int>());
    }

    if (ordering.size() != sz)
        ordering.clear();

    return ordering;
}


vector<int> lexicographical_order_v2(const GRAPH &adjList) {
    int sz = adjList.size();
    vector<int> ordering;
    vector<int> indegree(sz);
    for (int node = 0; node < sz; node++) 
        for (int neighbour : adjList[node])
            indegree[neighbour]++;

    priority_queue<int, vector<int>, greater<int> > ready;
    for (int node = 0; node < sz; node++) 
        if (indegree[node] == 0)
            ready.push(node);
        
    while (!ready.empty()) {
        int cur = ready.top();
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

    vector<int> lexicographical = lexicographical_order_v2(graph);
    for (auto n : lexicographical) 
        cout << n << " ";
    cout << "\n";
    return 0;
}

/*
8 10
5 0
5 7
6 7
6 8
1 2
0 1
7 2
8 2
2 4
2 3
*/