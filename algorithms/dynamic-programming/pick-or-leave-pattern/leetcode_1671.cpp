/****************************************************
 *** Problem Number : 1671
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int memory1[MAX];
int memory2[MAX];

int LDS_start(vector<int> &nums, int idx) {
  if (idx >= nums.size())
    return 0;

  auto &ret = memory1[idx];
  if (ret != -1) return ret;

  int ret = 0;
  for (int next = idx + 1; next < nums.size(); next++)
    if (nums[idx] > nums[next])
      ret = max(ret, LDS_start(nums, next));
  ret += 1;
  return ret;
}

int LDS_end(vector<int> &nums, int idx) {
  if (idx < 0)
    return 0;
  auto &ret = memory2[idx];
  if (ret != -1) return ret;

  int ret = 0;
  for (int prv = idx - 1; prv >= 0; prv--) 
    if (nums[idx] > nums[prv])
      ret = max(ret, LDS_end(nums, prv));
  ret += 1;
  return ret;
}

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
      memset(memory1, -1, sizeof(memory1));
      memset(memory2, -1, sizeof(memory2));
      int n = nums.size();
      
      int answer = 0;
      for (int i = 1; i < n -1; i++) {
        int cur = LDS_start(nums, i) + LDS_end(nums, i) - 1;
        answer = max(answer, cur);
      }

      return n - answer;

    }
};