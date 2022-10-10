/****************************************************
 *** Problem Number : 813
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/largest-sum-of-averages/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
double memory[MAX][MAX];

double mx_averages(vector<int> &nums, int k, int idx) {
  if (idx >= nums.size())
    return 0;

  if (k == 0)
    return INT_MIN;
  
  auto &ret = memory[idx][k];
  if (ret != -1) return ret;

  double sum = 0;
  ret = INT_MIN;
  for (int i = idx; i < nums.size(); i++) {
    sum += nums[i];
    ret = max(ret, sum/(i - idx + 1) + mx_averages(nums, k - 1, i + 1));
  }
  return ret;
}

class Solution {
public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++)
        memory[i][j] = -1;
    return mx_averages(nums, k, 0);
  }
};

int main()
{
  Solution s;
  vector<int> v{9,1,2,3,9};
  cout << s.largestSumOfAverages(v, 3);
  return 0;
}