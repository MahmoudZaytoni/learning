/****************************************************
 *** Problem Number : 72
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/edit-distance/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int memory[MAX][MAX];

class Solution {
  string str1, str2;
  int mn(int idx1, int idx2) {
    if (idx1 >= str1.size()) // base case
      return str2.size() - idx2;
    if (idx2 >= str2.size()) // base case
      return str1.size() - idx1;

    auto &ret = memory[idx1][idx2];
    if (ret != -1) return ret;

    if (str1[idx1] == str2[idx2])
      return ret = mn(idx1 + 1, idx2 + 1);
    
    int change = 1 + mn(idx1 + 1, idx2 + 1);
    int delete_ = 1 +  mn(idx1 + 1, idx2);
    int insert = 1 + mn(idx1, idx2 + 1);

    return ret = min(change, min(delete_, insert));
  }
public:
    int minDistance(string word1, string word2) {
        memset(memory, -1, sizeof(memory));
        str1 = word1, str2 = word2;
        return mn(0,0);
    }
};