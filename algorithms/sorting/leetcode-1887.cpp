/****************************************************
 *** Problem Title : 1887. Reduction Operations to Make the Array Elements Equal
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;  
      sort(nums.begin(), nums.end());
      int cnt = 0, res = 0;
      int last = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != last) {
          cnt++;
          last = nums[i];
        }
        res += cnt;
      }
      return res;
    }
};