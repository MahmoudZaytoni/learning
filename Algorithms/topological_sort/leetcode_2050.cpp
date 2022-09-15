// 2050. Parallel Courses III
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
    }

    int topSort(GRAPH &adjList, vector<int> &time) {
        vector<int> indegree(adjList.size());

         
        for (int node = 0; node < adjList.size(); node++) 
            for (int neighbour : adjList[node])
                indegree[neighbour]++;
        
        queue<int> ready;
        for (int node = 0; node < adjList.size(); node++)
            if (indegree[node] == 0)
                ready.push(node);

        vector<int> completion_time(adjList.size());
        while (!ready.empty()) {
            int cur = ready.front();
            ready.pop();

            completion_time[cur] += time[cur];
            for (int neighbour : adjList[cur]) {
                if (--indegree[neighbour] == 0)
                    ready.push(neighbour);
                
                completion_time[neighbour] = max(completion_time[neighbour], completion_time[cur]);
            }
        }
        return *max_element(completion_time.begin(), completion_time.end());
    }


public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        GRAPH graph(n);

        for (auto &relation : relations)
            add_directed_edge(graph, relation[0] - 1, relation[1] - 1);

        return topSort(graph, time);
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> relations{{1,5}, {2,5}, {3,5}, {3,4}, {4,5}};
    vector<int> time{1,2,3,4,5};
    Solution s;
    cout << s.minimumTime(n,relations,time) << "\n";
    return 0;
}