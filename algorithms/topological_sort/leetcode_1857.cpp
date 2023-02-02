// 1857. Largest Color Value in a Directed Graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef vector<vector<int>> GRAPH;
class Solution {

    void add_directed_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
    }


    int largestColor(GRAPH &adjList, string &colors) {
        vector<int> indegree(adjList.size());

        for (int node = 0; node < adjList.size(); node++) 
            for (int neighbour : adjList[node])
                indegree[neighbour]++;
        
        queue<int> ready;
        for (int node = 0; node < adjList.size(); node++)
            if (indegree[node] == 0)
                ready.push(node);
        
        int found_nodes = 0, ans = 0;
        vector<vector<int>> mxColor(adjList.size(), vector<int>(26));
        while (!ready.empty()) {
            int cur = ready.front(), color = colors[cur] - '0';
            ready.pop();
            ++found_nodes;
            ++mxColor[cur][color];

            ans = max(ans, mxColor[cur][color]);
            for (int i : adjList[cur]) {
                if (--indegree[i] == 0)
                    ready.push(i);
                
                for (int col = 0; col < 26; ++col)
                    mxColor[i][col] = max(mxColor[i][col], mxColor[cur][col]);
            }
        }

        if (found_nodes != adjList.size())
            return -1;
        return ans;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        GRAPH graph(colors.length());

        for (auto &edge : edges)
            add_directed_edge(graph, edge[0], edge[1]);
        
        return largestColor(graph, colors);
    }
};

int main()
{
    vector<vector<int>> edges{{0,1}, {0,2}, {2,3}, {3,4}, {4,5}};
    string color = "abaca";
    Solution s;
    cout << s.largestPathValue(color,edges) << "\n";
    return 0;
}