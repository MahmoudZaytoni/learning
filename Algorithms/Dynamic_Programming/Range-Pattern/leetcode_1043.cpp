/****************************************************
 *** Problem Number : 1043
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/partition-array-for-maximum-sum/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


const int MAX = 500 + 1;
int memory[MAX];

int mxSum(vector<int> &arr, int k, int idx) {
  if (idx >= arr.size())
    return 0;
  
  int &ret = memory[idx];
  if (ret != -1) return ret;

  int mx_item = INT_MIN, items_so_far = 0;
  for (int i = idx; i < arr.size(); i++) {
    mx_item = max(arr[i], mx_item);
    items_so_far++;

    if (items_so_far <= k)
      ret = max(ret, mx_item * items_so_far + mxSum(arr, k, idx + 1));
  }
  return ret;
}


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(memory, -1, sizeof(memory));
        return mxSum(arr, k, 0);
    }
};