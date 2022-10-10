/****************************************************
 *** Problem Number : 221. Maximal Square
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/maximal-square/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 300 + 1;
int memory[MAX][MAX];

int mxSquare(vector<vector<char>> &matrix, int r, int c) {
  int rows = matrix.size(), columns = matrix[0].size();
  if (r >= rows || c >= columns || matrix[r][c] == '0')
    return 0;
  
  int &ret = memory[r][c];
  if (ret != -1) 
    return ret;
  
  int right = mxSquare(matrix, r, c + 1);
  int down = mxSquare(matrix, r + 1, c);
  int diagonal = mxSquare(matrix, r + 1, c + 1);
  return ret = 1 + min({right, down, diagonal});
}

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    memset(memory, -1, sizeof(memory));
    int mx = 0;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            mx = max(mx,mxSquare(matrix, i, j));
    return mx * mx;
  }
};
 

int main()
{
  vector<vector<char>> v{{'0', '1'}, {'1', '0'}};
  Solution s;
  cout << s.maximalSquare(v) << "\n";
  return 0;
}