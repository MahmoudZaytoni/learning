/****************************************************
 *** Problem Number : 1143
 *** Problem Title  : longest common subsequence
 *** Diffculty      : medium
 *** URL            : https://leetcode.com/problems/longest-common-subsequence/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX][MAX];

class Solution {
  string str1, str2;

  int LCS(int idx1, int idx2) {
    if (idx1 == str1.size() || idx2 == str2.size())
      return 0;
    
    auto &ret = memory[idx1][idx2];
    if (ret != -1)
      return ret;
    
    if (str1[idx1] == str2[idx2])
      return ret = 1 + LCS(idx1 + 1, idx2 + 1);

    int choice1 = LCS(idx1 + 1, idx2);
    int choice2 = LCS(idx1, idx2 + 1);
    return ret = max(choice1, choice2);
  }

public:
    int longestCommonSubsequence(string text1, string text2) {
        str1 = text1, str2 = text2;

        memset(memory, -1, sizeof(memory));
        return LCS(0,0);
    }
};