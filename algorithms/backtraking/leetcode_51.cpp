/****************************************************
 *** Problem Number : 51. N-Queens
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/n-queens/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    void backtrack(vector<vector<string>> &res, vector<string> &cur_grid, vector<int> &cols, int r) {
      if (r == n) {
        res.push_back(cur_grid);
        return;
      }

      for (int col = 0; col < n; col++) {
        bool valid = true;
        
        for (int k = 0; k < r && valid; k++) 
          if (cols[k] == col || r + col == k + cols[k] ||  r - col == k - cols[k])
            valid = false;
        
        if (valid) {
          cols[r] = col;
          cur_grid[r][col] = 'Q';
          backtrack(res, cur_grid, cols, r+1);
          cols[r] = 0;
          cur_grid[r][col] = '.';
        }
      }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
      this->n = n;
      vector<vector<string>> res;
      vector<string> cur_grid(n, string(n, '.'));
      vector<int> cols(n);
      backtrack(res, cur_grid, cols, 0);
      return res;
    }
};