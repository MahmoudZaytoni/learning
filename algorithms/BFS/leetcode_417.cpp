// Pacific Atlantic Water Flow
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#define OO 1e9
using namespace std; 

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, vector<vector<int>> &heights) {
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size())
            return false;
        return true;
    }

    struct cell {
        int r;
        int c;
    };

    void bfs(vector<vector<int>> &heights, vector<cell> &starts, vector<vector<bool>> &visited) {
        queue<cell> q;

        for (cell &cell : starts) {
            q.push(cell);
            visited[cell.r][cell.c] = 1;
        }

        for (int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                cell cur = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int r = cur.r, c = cur.c;
                    int nr = cur.r + dx[d], nc = cur.c + dy[d];
                    if (!isValid(nr,nc,heights) || visited[nr][nc] || heights[r][c] > heights[nr][nc])
                        continue;

                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<cell> pacificStarts, AtlanticStarts;
        vector<vector<bool>> pacific(rows,vector<bool>(cols)), atlantic(rows,vector<bool>(cols));

        for (int r = 0; r < rows; r++) {
            pacificStarts.push_back({r,0});
            AtlanticStarts.push_back({r,cols-1});
        }

        for (int c = 0; c < cols; c++) {
            pacificStarts.push_back({0,c});
            AtlanticStarts.push_back({rows-1, c});
        }

        bfs(heights,pacificStarts,pacific);
        bfs(heights,AtlanticStarts,atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (atlantic[i][j] && pacific[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}