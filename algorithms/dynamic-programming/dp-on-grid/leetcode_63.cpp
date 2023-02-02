/****************************************************
 *** Problem Number : 63. Unique Paths II
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/unique-paths-ii/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, vector<vector<int>> &matrix) {
  if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size())
    return false;
  return true; 
}
const int MAX = 100 + 1;
int memory[MAX][MAX];
int count(int r, int c, vector<vector<int>> &obst) {
  if (!isValid(r,c, obst))
    return 0;

  if (obst[r][c])
    return 0;

  if (r+1 == obst.size() && c+1 == obst[0].size())
    return true;

  int &ret = memory[r][c];
  if (ret != -1) return ret;

  int right = count(r, c+1,obst);
  int bottom = count(r+1, c, obst);

  return ret = right + bottom;
}

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    memset(memory, -1, sizeof(memory));
    return count(0,0, obstacleGrid);
  }
};