/****************************************************
 *** Problem Number : 1312
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int memory[MAX][MAX];

int mnPalindrom(string &s, int start, int end) {
  if (start >= end)
    return 0;
  
  int &ret = memory[start][end];
  if (ret != -1 ) return ret;

  if (s[start] == s[end])
    return ret = mnPalindrom(s, start + 1, end - 1);
  
  int insert_left = 1 + mnPalindrom(s, start + 1, end);
  int insert_right = 1 + mnPalindrom(s, start, end - 1);
  return ret = min(insert_left, insert_right);
}

class Solution {
public:
    int minInsertions(string s) {
      memset(memory, -1, sizeof(memory));
      return mnPalindrom(s, 0, (int)s.size() - 1);
    }
};