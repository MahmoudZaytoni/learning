// 210. Course Schedule II
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

class Solution {

    void add_directed_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
    }
public:
    vector<int> topSort(GRAPH &adjList) { // O(E + V) using topSort
        int sz = adjList.size();

        vector<int> indegree(sz);
        for (int node = 0; node < sz; node++) {
            for (int neighbour : adjList[node])
                indegree[neighbour]++;
        }

        queue<int> ready;
        for (int i = 0; i < sz; i++) 
            if (indegree[i] == 0)
                ready.push(i);

        int levels = 0;
        vector<int> ordering;
        while (!ready.empty()) {
            int level_sz = ready.size();
            while (level_sz--) {
                int node = ready.front();
                ready.pop();
                ordering.push_back(node);

                for (int neighbour : adjList[node])
                    if (--indegree[neighbour] == 0)
                        ready.push(neighbour);
            }
            levels++;
        }

        if (ordering.size() != sz)
            ordering.clear();
        return ordering;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        GRAPH adjList(n);

        for (auto relation : prerequisites) 
            add_directed_edge(adjList, relation[1], relation[0]);

        return topSort(adjList);
    }
};
