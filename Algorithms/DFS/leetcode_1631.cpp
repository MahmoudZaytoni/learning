// 1631. Path With Minimum Effort

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int dx[4] = {0, 0, 1 , -1};
    int dy[4] = {1, -1, 0, 0 };

    bool isValid(int r, int c, vector<vector<int>> &matrix) {
        if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size())
            return false;
        return true;
    }

    bool dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<int>> &height, int limit) {
        if (r + 1 == height.size() && c + 1 == height[0].size()) 
            return true;

        visited[r][c] = 1;
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d] , nc = c + dy[d];
            if (!isValid(nr, nc, height) || visited[nr][nc] || abs(height[r][c] - height[nr][nc]) > limit)
                continue;
            if (dfs(nr,nc,visited, height, limit))
                return true;
        }
        return false;
    }

    bool possible(vector<vector<int>> &height,int mid) {
        vector<vector<bool>> visited(height.size(), vector<bool>(height[0].size()));
        return dfs(0,0, visited, height, mid);
    }
    

    int binarySearch(vector<vector<int>> &height) {
        int start = 0, end = 1e6;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(height, mid))
                end = mid - 1, ans = mid;
            else 
                start = mid + 1;
        }
        return ans;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return binarySearch(heights);
    }
};