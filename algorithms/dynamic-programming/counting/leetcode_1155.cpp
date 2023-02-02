/****************************************************
 *** Problem Number : 1155
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
const int MOD = 1e9 + 7;
int memory[MAX];

class Solution {
  int count(int n, int k, int target) {
    if (n == 0)
      return target == 0;
    if (target < 0)
      return false;
    
    int &ret = memory[target];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 1; i <= k; i++) {
      ret += count(n-1, k, target - i) % MOD;
    }
    return ret % MOD;
  }
public:
  int numRollsToTarget(int n, int k, int target) {
    memset(memory, -1, sizeof(memory));

  }
};