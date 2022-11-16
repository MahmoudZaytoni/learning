/****************************************************
 *** Problem Number : 1351
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


class Solution {
    int binarySearch(vector<vector<int>>& grid) {
        int ans = 0;
        int len = (int)grid[0].size();
        for (int i = 0; i < grid.size(); i++)  {
            int l = 0, r = len - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (grid[i][mid] >= 0)
                    l = mid+1;
                else
                    r = mid-1;
            }
            ans += len - r;
        }
        return ans;
    }

    /*  
        X = negative number , * = positive number
            ****XXX
            ***XXXX
            **XXXXX
            *XXXXXX
            XXXXXXX
        optimization 
        We can traverse from upper right to  lower left
        and the time complexty will be O(n + m)
    */
    int followUp(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = (int)grid[0].size();
        int ans = 0;
        int j = cols - 1;
        for (int i = 0; i < rows; i++) {
            while (j >= 0 && grid[i][j] >= 0)
                j--;
            ans += cols - j - 1;
        }
        return ans;
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        return followUp(grid);
    }
};