#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX][MAX];
class Solution {
  bool isPalindrum(string &s, int start, int end) {
    if (start >= end)
      return 1;
    int &ret = memory[start][end];
    if (ret != -1) return ret;

    if (s[start] == s[end])
      ret = isPalindrum(s, start + 1, end - 1);

    return ret = 0;
  }
public:
    string longestPalindrome(string s) {
      memset(memory, -1 ,sizeof(memory));
      int idx = -1, length = 0;
      int sz = s.size();
      for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
          int len = j - i + 1;
          if (isPalindrum(s, i, j) && len > length)
            length = len, idx = i;
        }
      }
      return s.substr(idx, length);
    }
};