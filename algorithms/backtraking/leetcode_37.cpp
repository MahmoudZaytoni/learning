/****************************************************
 *** Problem Number : 37. Sudoku Solver
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/sudoku-solver/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool canPlace(vector<vector<char>>& board, int r, int c, char d) {
    for (int i = 0; i < 9; i++)
      if (board[r][i] == d || board[i][c] == d)
        return false;

    r = (r / 3) * 3, c = (c / 3) * 3;
    for (int i = r; i < r+3; i++)
      for (int j = c; j < c+3; j++)
        if (board[i][j] == d)
          return false;
    return true;
  }

  void backtrack(vector<vector<char>>& board, int cell) {
    if (cell >= 81)
      return;
    
    int r = cell / 9, c = cell % 9;

    if (board[r][c] != '.')
      backtrack(board, cell+1);
    
    for (char d = '1'; d <= '9'; d++) {
      if (canPlace(board, r, c, d)) {
        board[r][c] = d;
        backtrack(board, cell+1);
        board[r][c] = '.';
      }
    }
    return;
  }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0);
    }
};