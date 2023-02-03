/****************************************************
 *** Problem Number : 912. Sort an Array
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/sort-an-array/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      const int SHIFT = 50000;
      int sz = (int)nums.size();
      for (int i = 0; i < sz; i++)
        nums[i] += SHIFT;

      int mx_element = nums[0];
      for (int i = 1; i < sz; i++)
        if (nums[i] > mx_element)
          mx_element = nums[i];

      vector<int> count(mx_element + 1);
      for (int i = 0; i < sz; i++)
        count[nums[i]] += 1;

      int idx = 0;
      for (int i = 0; i <= mx_element; i++)
        for (int j = 0; j < count[i]; j++, idx++)
          nums[idx] = i - SHIFT;
      return nums;
    }
};