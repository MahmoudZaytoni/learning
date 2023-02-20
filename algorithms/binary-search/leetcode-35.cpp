/****************************************************
 *** Problem Title : 35. Search Insert Position
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/search-insert-position/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return idx;
  }
};