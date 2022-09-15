// 329. Longest Increasing Path in a Matrix
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

class Solution {
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    void add_directed_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
    }

    bool isValid(int r, int c, vector<vector<int>> &matrix) {
        if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size())
            return false;
        return true;
    }

    struct node {
        int r, c;
    };

    pair<vector<node>, int> neighbours(int r, int c, vector<vector<int>> &matrix) {
        vector<node> edges;
        int indegree = 0;
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];

            if (!isValid(nr,nc,matrix))
                continue;

            if (matrix[r][c] < matrix[nr][nc]) {
                edges.push_back({nr,nc});
            } else if (matrix[r][c] > matrix[nr][nc]){
                indegree++;
            }
        }
        return {edges, indegree};
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> indegree(rows, vector<int>(cols));


        queue<node> ready;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                indegree[r][c] = neighbours(r,c,matrix).second;

                if (indegree[r][c] == 0)
                    ready.push({r,c});
            }
        }

        int levels = 0;
        while (!ready.empty()) {
            int level_sz = ready.size();
            while (level_sz--) {
                node cur = ready.front();
                ready.pop();
                
                vector<node> neighbours_nodes = neighbours(cur.r,cur.c, matrix).first;
                for (auto node : neighbours_nodes) {
                    if (--indegree[node.r][node.c] == 0)
                        ready.push(node);
                }
            }
            levels++;
        }
        return levels;
    }
};