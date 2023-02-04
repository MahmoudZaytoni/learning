/****************************************************
 *** Problem Title  : 1005. Maximize Sum Of Array After K Negations
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int idx = 0;
      while (k--) {
        if (idx + 1 == nums.size())
          nums[idx] *= -1;
        else if (-1 * nums[idx] > nums[idx+1])
          nums[idx++] *= -1;
        else 
          nums[idx] *= -1;
      }
      return accumulate(nums.begin(), nums.end(), 0L);
    }
};