/****************************************************
 *** Problem Number : 746
 *** Diffculty      : easy
 *** URL            : https://leetcode.com/problems/min-cost-climbing-stairs/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX];

class Solution {
  int mn(vector<int> &cost, int idx) {
    if (idx >= cost.size() || idx + 1 >= cost.size())
      return 0;
    int &ret = memory[idx];
    if (ret != -1) return ret;

    // peak current or peak next
    int cur = cost[idx] + mn(cost, idx + 1);
    int next = cost[idx+1] + mn(cost,idx+2);
    return min(cur,next);
  }

public:
    int minCostClimbingStairs(vector<int>& cost) {
      memset(memory, -1, sizeof(memory));
      return mn(cost, 0);
    }
};