/****************************************************
 *** Problem Number : 518
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/coin-change-ii/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300 + 1;
const int MAX_V = 5000 + 1;
int memory[MAX_N][MAX_V];

class Solution {
  int count_coins_change(vector<int> &coins, int idx, int target) {
    if (target < 0)
      return false;
    if (target == 0)
      return true;
    if (idx == coins.size())
      return false;
    
    auto &ret = memory[idx][target];
    if (ret != -1) return ret;

    int leave = count_coins_change(coins, idx + 1, target);
    int pick = 0;
    if (coins[idx] <= target)
      pick = count_coins_change(coins, idx, target - coins[idx]);

    return ret = leave + pick;
  }
public:
  int change(int amount, vector<int>& coins) {
    memset(memory, -1, sizeof(memory));
    return count_coins_change(coins, 0, amount);
  }
};