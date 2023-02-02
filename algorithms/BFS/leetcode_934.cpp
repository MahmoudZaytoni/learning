// 934. Shortest Bridge

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#define OO 1e9
using namespace std;


class Solution {
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};

    bool isValid(int r,int c, vector<vector<int>> &grid) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) 
            return false;
        return true;
    }

    struct cell {
        int r{};
        int c{};
    };

    void dfs(int r, int c, queue<cell> &q, vector<vector<int>> &grid) {
        grid[r][c] = 2;
        q.push({r,c});
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if (!isValid(nr,nc,grid) || grid[nr][nc] != 1)
                continue;
            dfs(nr,nc,q,grid);
        }
    }
    
public:

    int shortestBridge(vector<vector<int>>& grid) {
        queue<cell> q;
        
        bool flag = 1;
        for (int i = 0; i < grid.size() && flag; i++) {
            for (int j = 0; j < grid[0].size() && flag; j++) {
                if (grid[i][j]) {
                    flag = 0;
                    dfs(i,j,q,grid);
                }
            }
        }


        for (int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                cell cur = q.front();
                q.pop();

                 
                for (int d = 0; d < 4; d++) {
                    int nr = cur.r + dx[d], nc = cur.c + dy[d];
                    if (!isValid(nr,nc,grid) || grid[nr][nc] == 2 || grid[nr][nc] == 3)
                        continue;

                    if (grid[nr][nc] == 1)
                        return level;

                    grid[nr][nc] = 3;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> v({
    {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}}});

    cout << s.shortestBridge(v) << "\n"; 
    
    return 0;
}