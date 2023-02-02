/****************************************************
 *** Problem Number : 1061. Lexicographically Smallest Equivalent String
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


typedef vector<vector<bool>> GRAPH;

class Solution {
  GRAPH adjMat;
  
  void dfs(int c, vector<bool> &visited, vector<int> &component, int &mnChar) {
    if (visited[c])
      return;
    
    visited[c] = 1;
    component.push_back(c);

    if (c < mnChar)
      mnChar = c;

    for (int i = 0; i < 26; i++) {
      if (adjMat[c][i])
        dfs(i, visited, component, mnChar);
    }
  }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
      adjMat = vector<vector<bool>> (26, vector<bool>(26));

      for (int i = 0; i < s1.size(); i++) {
        adjMat[s1[i] - 'a'][s2[i] - 'a'] = 1;
        adjMat[s2[i] - 'a'][s1[i] - 'a'] = 1;
      }

      vector<bool> visited(26);
      vector<int> mp(26);

      for (int i = 0; i < 26; i++) {
        if (visited[i])
          continue;

        vector<int> component;
        int mnChar = 50;

        dfs(i, visited, component, mnChar);

        for (auto c : component) {
          mp[c] = mnChar;
        }
      }

      for (int i = 0; i < baseStr.size(); i++) {
        char ch = baseStr[i];
        if (!mp[ch - 'a'])
          baseStr[i] = mp[ch-'a'] + 'a';
      }
      return baseStr;
    }
};


int main()
{
  Solution s;
  string ans = s.smallestEquivalentString("parker", "morris", "parser");
  cout << ans << "\n";
  return 0;
}