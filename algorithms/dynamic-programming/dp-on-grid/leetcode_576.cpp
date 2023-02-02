/****************************************************
 *** Problem Number : 576. Out of Boundary Paths
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/out-of-boundary-paths/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

const int MAX = 50 + 1;
const int mod = 1e9 + 7;
int memory[MAX][MAX];

int find(int r, int c, int maxMove, int rows, int columns) {
  if (r < 0 || c < 0 || r >= rows || c >= columns )
    return true;
  
  if (maxMove <= 0)
    return false;

  auto &ret = memory[r][c];
  if (ret != -1 ) return ret;

  ret = 0;
  for (int d = 0; d < 4; d++) {
    int nr = r + dx[d], nc = c + dy[d];
    ret += find(nr,nc, maxMove - 1, rows, columns);
    ret %= mod;
  }
  return ret % mod;
}

class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(memory, -1, sizeof(memory));
    return find(startRow, startColumn, maxMove, m, n);
  }
};