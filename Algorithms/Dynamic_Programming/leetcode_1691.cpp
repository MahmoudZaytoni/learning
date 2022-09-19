/****************************************************
 *** Problem Number : 1691
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];

class Solution {
  bool less_eq(vector<vector<int>> &cuboids,int i, int j) {
    return cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2];
  }
    
  int LIS(vector<vector<int>> &arr,int idx) {
    if (idx == arr.size())
      return 0;

    auto &ret = memory[idx];
    if (ret != -1)
      return ret;
    
    ret = 0;
    for (int i = idx + 1; i < (int)arr.size(); i++)
      if (less_eq(arr, idx, i))
        ret = max(ret, LIS(arr, i));
    ret += arr[idx][2];
    return ret;
  }

public:
    //cuboid[i] = [widthi, lengthi, heighti] (0-indexed)
    int maxHeight(vector<vector<int>>& cuboids) {
        memset(memory, -1, sizeof(memory));

        for (auto &c : cuboids)
          sort(c.begin(), c.end());
        
        sort(cuboids.begin(), cuboids.end());

        return LIS(cuboids, 0);

    }
};