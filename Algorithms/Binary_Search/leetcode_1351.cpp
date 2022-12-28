
#include<iostream>
#include<vector>
#include <algorithm>
#include <map>
#include "unordered_map"
#include<string>
#include "unordered_set"
using namespace std;


class Solution {
public:
    // ********** YOUR CODE BEGINS HERE ************** //
    int countNegatives(vector<vector<int>>& grid) {
        int method = 1; // choose which method to run
        int counter = 0; // counts the number of negatives in the grid

        if(method == 1) { // brute force method
            counter = bruteForce(grid);

        } else if(method == 2) { // Binary Search method
            counter = binarySearch(grid);
        }
        else if (method == 3) { // follow-up method
            counter = followUp(grid);
        } else {
            counter = extraSolutionOptimization(grid);
        }
        return counter;
    }

    int bruteForce(vector<vector<int>>& grid) { // TC: O(n*m), SC: O(1)
        // implement your code here
        int row = grid.size(), cols = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < row; i++) 
          for (int j = 0; j < cols; j++)
            if (grid[i][j] < 0)
              cnt++;
        // NO EXTRA Space so the SC: o(1)
        return cnt;
    }

    int binarySearch(vector<vector<int>>& grid) { // TC = O(NlogM), SC = O(1)
        // implement your code here
        int ans = 0;
        int rows = grid.size(), cols = (int)grid[0].size();
        // for each row , search where is the first negative number
        for (int i = 0; i < rows; i++)  {
            int l = 0, r = cols - 1; // l = left , r = right
            while (l <= r) {
                int mid = (l + r) / 2;
                if (grid[i][mid] >= 0)
                    l = mid+1;
                else
                    r = mid-1;
            }
            ans += cols - r - 1;
        }
        return ans;
    }

    // GRAPH Solution Using DFS
    bool isValid(int r, int c, vector<vector<int>> &grid) {
      if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
        return false;
      return true;
    }

    int dfs(int r, int c, vector<vector<int>> &grid) { // TC = O(N) - SC = O(N)
    // N = Number of negative numbers on grid
      // if cell out of grid or cell is positive return 0
      if (!isValid(r,c,grid) || grid[r][c] >= 0) 
        return 0;

      // mark it in order to don't visit this cell again
      grid[r][c] = 0;
      int res = 1; // SC = O(N), becase it will created O(N) times on stack
      // traverse on 4 directions
      /*
      . X .
      X # X
      . X .
      */
      res += dfs(r+1,c, grid);
      res += dfs(r-1,c, grid);
      res += dfs(r, c+1, grid);
      res += dfs(r, c-1, grid);
      return res;
    }

    int followUp(vector<vector<int>>& grid) {  // BFS , DFS - graphs
        // implement your code here
        // TC = O(N), SC = O(N)
        return dfs((int)grid.size() - 1, (int)grid[0].size() - 1, grid);
    }


    /*  
        - = negative number , + = positive number
            ++++---
            +++----
            ++-----
            +------
            -------
        optimization 
        We can traverse from upper right to  lower left
        and the time complexty will be O(n + m)
    */

    int extraSolutionOptimization(vector<vector<int>>& grid) { // TC = O(N+M) , SC = O(1)
        int rows = grid.size(), cols = (int)grid[0].size();
        int ans = 0;
        int j = cols - 1;
        for (int i = 0; i < rows; i++) {
            while (j >= 0 && grid[i][j] < 0)
              j--;
            
            ans += cols - j - 1;
        }
        return ans;
    }


};



int main() {
    string EXCEPTION;

    Solution sol = Solution();

    map<string, vector<vector<int>>> gridMap = {
            {"8", {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}}},
            {"2", {{3, -1},{1, -2}}},
            {"3", {{1,-1},{-1,-1}}},
            {"1", {{-1}}},
            {"0", {{50}}},
            {"9", {{40, 30, -1, -2}, {23, 29, -1, -3}, {10, 16, -1, -5}, {9, -1, -2, -30}}},
    };

    int i = 1, cases = 6;
    for(auto &grid: gridMap) {
        int val = stoi(grid.first);
        int rs = sol.countNegatives(grid.second);

        if(rs != val) {
            EXCEPTION = "Wrong Answer:\n your output: " + to_string(rs) + " Expected: " + to_string(val);
            cout<<EXCEPTION<<endl;
            cout<< "====================\n";
            cout<< "TEST CASE: "<<endl;
            for(auto &row : grid.second){
                for(auto &num: row)
                    cout<< num << " ";
                cout<< endl;
            }
            break;
        }else {
            cout<< "TEST CASE " << i++ << "/" << cases << " PASSED " <<endl;
        }
    }
    return 0;
}

