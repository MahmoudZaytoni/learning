// 310. Minimum Height Trees
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_undirected_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> topSort(GRAPH &adjList) {
        vector<int> indegree(adjList.size());

        for (auto &nodes : adjList) 
            for (auto neighbours : nodes)
                indegree[neighbours]++;
        
        queue<int> ready;
        for (int node = 0; node < adjList.size(); node++)
            if (indegree[node] == 1)
                ready.push(node);
        
        int sz = adjList.size();
        while (sz > 2) {
            int level_sz = ready.size();
            sz -= level_sz;
            while (level_sz--) {
                int cur = ready.front();
                ready.pop();

                for (auto neighbour : adjList[cur])
                    if (--indegree[neighbour] == 1)
                        ready.push(neighbour);
            }
        }

        vector<int> result;
        while (!ready.empty()) {
            result.push_back(ready.front());
            ready.pop();
        }
        return result;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        GRAPH graph(n);

        for (auto &edge : edges) 
            add_undirected_edge(graph, edge[0], edge[1]);

        return topSort(graph);
    }
};
 
int main() 
{
    return 0;
}