/****************************************************
 *** Problem Number : 491. Non-decreasing Subsequences
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/non-decreasing-subsequences/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> nums;
  vector<int> sequence;
  set<vector<int>> res;
  void backtrack(int idx) {
    if (idx == nums.size() && sequence.size() > 1) {
      res.insert(sequence);
      return;
    } else if (idx == nums.size())
      return;
    
    if (sequence.empty() || sequence.back() <= nums[idx]) {
      sequence.push_back(nums[idx]);
      backtrack(idx+1);
      sequence.pop_back();
    }
    backtrack(idx+1);
  }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      this->nums = nums;
      backtrack(0);
      return vector(res.begin(), res.end());
    }
};