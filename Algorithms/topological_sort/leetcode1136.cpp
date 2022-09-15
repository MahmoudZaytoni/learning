// 1136. Parallel Courses
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
    int longest_path(GRAPH &adjList) { // O(E + V) using topSort
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

        int levels = 0, found_nodes = 0;
        while (!ready.empty()) {
            int level_sz = ready.size();
            while (level_sz--) {
                int node = ready.front();
                ready.pop();
                ++found_nodes;

                for (int neighbour : adjList[node])
                    if (--indegree[neighbour] == 0)
                        ready.push(neighbour);
            }
            levels++;
        }

        if (found_nodes != sz)
            return -1;
        return levels;
    }
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        GRAPH adjList(n);

        for (auto relation : relations) 
            add_directed_edge(adjList, relation[0], relation[1]);

        return longest_path(adjList);
    }
};

int main()
{

    int nodes, edges; cin >> nodes >> edges;

    GRAPH graph(nodes + 1);
    for (int e = 0; e < edges; e++) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
    }

    Solution s;
    cout << s.longest_path(graph) << "\n";
    return 0;
} 