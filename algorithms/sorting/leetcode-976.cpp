/****************************************************
 *** Problem Title  : 976. Largest Perimeter Triangle
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/largest-perimeter-triangle/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i + 2 < (int)nums.size(); i++)
          if (nums[i] < nums[i+1] + nums[i+2])
            return nums[i] + nums[i+1] + nums[i+2];
        return 0;
    }
};