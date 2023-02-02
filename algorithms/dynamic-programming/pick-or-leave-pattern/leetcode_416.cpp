/****************************************************
 *** Problem Number : 416
 *** Diffculty      : medium
 *** URL            : https://leetcode.com/problems/partition-equal-subset-sum/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200 + 1;
const int MAX_T = 100 * 100 + 1;
int memory[MAX_N][MAX_T];
class Solution {
  bool can_subset_sum(vector<int> &v, int idx, int sum) {
    if (sum == 0)  
      return true;
    if (idx >= (int)v.size() || sum < 0)
      return false;
    auto &ret = memory[idx][sum];
    if (ret != -1) return ret;
    return ret = can_subset_sum(v, idx+1, sum - v[idx]) || can_subset_sum(v,idx+1,sum);
  }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &it : nums)
          sum += it;
        
        if (sum & 1)
          return false;
        
        memset(memory, -1, sizeof(memory));
        return can_subset_sum(nums, 0, sum / 2);
      
        
    }
};