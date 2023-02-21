/****************************************************
 *** Problem Title  : 540. Single Element in a Sorted Array
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/single-element-in-a-sorted-array/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int low = 1, high = (int)nums.size()-1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (mid & 1) {
        if (nums[mid] == nums[mid-1])
          low = mid+1;
        else if (nums[mid] == nums[mid+1])
          high = mid-1;
        else
          return nums[mid];
      }
      else if (mid % 2 == 0) {
        if (nums[mid] == nums[mid+1])
          low = mid+1;
        else if (nums[mid] == nums[mid-1])
          high = mid-1;
        else
          return nums[mid];
      }
    }
    return nums[0];
  }
};