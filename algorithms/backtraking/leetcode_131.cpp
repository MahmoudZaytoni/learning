/****************************************************
 *** Problem Number : 131. Palindrome Partitioning 
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/palindrome-partitioning/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 16 + 1;
int memory[MAX][MAX];
class Solution {
  bool is_Palindrome(string &s, int start, int end) {
    if (start >= end)
      return 1;

    int &ret = memory[start][end];
    if (ret != -1) return ret;

    if (s[start] != s[end])
      return ret = 0;

    return ret = is_Palindrome(s, start+1, end-1);
  }
public:
  void dfs(vector<vector<string>> &result, string &s, vector<string> &current_list, int start) {
    if (start >= s.length()) result.push_back(current_list);
    for (int end = start; end < s.length(); end++) {
      if (is_Palindrome(s, start, end)) {
        current_list.push_back(s.substr(start, end - start + 1));
        dfs(result, s, current_list, end+1);
        current_list.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    memset(memory, -1 ,sizeof(memory));
    vector<vector<string>> result;
    vector<string> current_list;
    dfs(result, s, current_list, 0);
    return result;
  }
};