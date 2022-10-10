/****************************************************
 *** Problem Number : 343
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/integer-break/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


const int MAX = 50 + 1;
int memory[MAX];

class Solution {
  int mxBreak(int n) {
    if (n <= 1)
      return 1;
    
    auto &ret = memory[n];
    if (ret != -1) return ret;

    ret = n;
    for (int i = 1; i <= n; i++)
      ret = max(ret, i * mxBreak( n - i));
    return ret;
  }

public:
    int integerBreak(int n) {
      if (n == 3 || n == 2)
        return n - 1;
      memset(memory, -1, sizeof(memory));
      return mxBreak(n);
    }
};