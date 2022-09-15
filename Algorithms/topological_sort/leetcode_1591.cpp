// 1591. Strange Printer II
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}

int topSort(GRAPH &adjList) {
    int sz = adjList.size();
    vector<int> indegree(sz);
    for (int node = 0; node < adjList.size(); node++)
        for (int neighbour : adjList[node])
            indegree[neighbour]++;
    
    queue<int> ready;
    for (int node = 0; node < sz; node++) 
        if (indegree[node] == 0)
            ready.push(node);
    
    int found_nodes = 0;
    while (!ready.empty()) {
        int cur = ready.front();
        ready.pop();
        ++found_nodes;
        
        for (int neighbour : adjList[cur])
            if (--indegree[neighbour] == 0)
                ready.push(neighbour);
    }
    if (found_nodes != sz)
        return false;
    return true;

}
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size(), cols = targetGrid[0].size();
        const int mxColor = 60 + 1; // 1 based

        // each color has grid
        vector<int> rmax(mxColor, -1), rmin(mxColor, rows);
        vector<int> cmax(mxColor, -1), cmin(mxColor, cols);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int color = targetGrid[r][c];
                rmax[color] = max(rmax[color], r);
                rmin[color] = min(rmin[color], r);
                cmax[color] = max(cmax[color], c);
                cmin[color] = min(cmin[color], c);
            }
        }
        GRAPH graph(mxColor);
        for (int color = 0; color < mxColor; color++)
            for (int r = rmin[color]; r <= rmax[color]; r++)
                for (int c = cmin[color]; c <= cmax[color]; c++)
                    if (targetGrid[r][c] != color)
                        add_directed_edge(graph, color, targetGrid[r][c]);
        return topSort(graph);
    }
};

int main()
{

    return 0;
}