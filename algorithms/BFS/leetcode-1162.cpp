/****************************************************
 *** Problem Title  : 1162. As Far from Land as Possible
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/as-far-from-land-as-possible/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dx[4] = {1, 0, 0, -1};
  int dy[4] = {0, 1, -1, 0};
  const int OO = 1e9;
  bool isValid(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    if (r < 0 || c < 0 || r >= n || c >= n)
      return false;
    return true;
  }

  int bfs(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j])
          q.push({i, j});

    int distance = -1;
    for (int sz = q.size(); !q.empty(); distance++, sz = q.size()) {
      while (sz--) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
          int nr = cur.first + dx[d];
          int nc = cur.second + dy[d];

          if (!isValid(nr, nc, grid) || grid[nr][nc])
            continue;
          
          grid[nr][nc] = 1;
          q.push({nr, nc});
        }
      }
    }
    return !distance ? -1 : distance;
  }
public:
    int maxDistance(vector<vector<int>>& grid) {
      return bfs(grid);
    }
};

int main()
{
  vector<vector<int>> grid{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  Solution s;
  cout << s.maxDistance(grid) << endl;
  return 0;
}