/****************************************************
 *** Problem Number : 377
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/combination-sum-iv/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000 + 1;
int memory[MAX];

int count(vector<int> &nums, int target) {
  if (target < 0)
    return false;
  if (target == 0)
    return true;
  
  auto &ret = memory[target];
  if (ret != -1 ) return ret;

  ret = 0;
  for (int idx = 0; idx < nums.size(); idx++) {
    if (target >= nums[idx])
      ret += count(nums, target - nums[idx]);
  }
  return ret;
}

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    
  }
};