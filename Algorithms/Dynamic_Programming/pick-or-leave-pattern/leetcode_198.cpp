/****************************************************
 *** Problem Number : 198
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/house-robber/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 1;
int memory[MAX_N][MAX_N];


// MY Solution O(N) time - O(N^2) Space
class Solution {

  int mxRob(vector<int> &nums, int idx, int prev) {
    if (idx >= (int)nums.size())
      return 0;
    
    auto &ret = memory[idx][prev];
    if (ret != -1)
      return ret;
    
    int choice1 = mxRob(nums, idx + 1, prev); // leave it
    int choice2 = 0;

    if (prev == nums.size() || idx >= prev + 2)
      choice2 = nums[idx] + mxRob(nums, idx + 1, idx);

    return ret = max(choice1, choice2);
  }

public:
  int rob(vector<int>& nums) {
    memset(memory, -1, sizeof(memory));

    return mxRob(nums, 0, nums.size());

  }
};


// Better Solution 
int mem[MAX_N];
class Solution {
    int robber(vector<int> &nums, int idx) {
      if (idx >= nums.size())      
        return 0;
      
      auto &ret = mem[idx];
      if (ret != -1) 
        return ret;

      int skip = robber(nums, idx + 1);
      int rob = nums[idx] + robber(nums, idx + 2);
      return ret = max(skip, rob);
    }
public:
  int rob(vector<int>& nums) {
    memset(mem, -1, sizeof(mem));

    return robber(nums, 0);
  }
};