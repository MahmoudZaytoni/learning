/****************************************************
 *** Problem Number : 931. Minimum Falling Path Sum
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/minimum-falling-path-sum/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


const int MAX = 100 + 1;
int memory[MAX][MAX];
int dx[3] = {1, 1, 1};
int dy[3] = {0, -1, 1};

bool isValid(int c, vector<vector<int>> &matrix) {
  if (c < 0 || c >= matrix[0].size())
    return false;
  return true;
}


int mnSum(int r, int c, vector<vector<int>> &matrix) {
  if (r == (int)matrix.size())
    return 0;
  
  int &ret = memory[r][c];
  if (ret != -1) return ret;

  int mn = INT_MAX;
  for (int d = 0; d < 3; d++) {
    int nr = r + dx[d], nc = c + dy[d];
    if (!isValid(nc, matrix))
      continue;
    mn = min(mn, matrix[r][c] + mnSum(nr,nc, matrix));
  }
  return ret = mn;
}

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    memset(memory, -1, sizeof(memory));
    int mn = INT_MAX;
    for (int i = 0; i < matrix[0].size(); i++) {
      mn = min(mn, mnSum(0,i,matrix));
    }
    return mn;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> matrix{{2,1,3},{6,5,4},{7,8,9}};
  cout << s.minFallingPathSum(matrix) << "\n";
  return 0;
}