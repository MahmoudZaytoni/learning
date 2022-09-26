/****************************************************
 *** Problem Number : 297
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/perfect-squares/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000 + 1;
int memory[MAX];

int perfect(int n) {
  if (n <= 0)
    return 0;
  int &ret = memory[n];
  if (ret != -1) return ret;

  ret = INT_MAX;
  for (int i = 1; i * i <= n; i++) 
    ret = min(ret, 1 + perfect(n - (i*i)));
  
  return ret;
}


class Solution {
public:
    int numSquares(int n) {
      memset(memory, -1, sizeof(memory));
      return perfect(n);
    }
};