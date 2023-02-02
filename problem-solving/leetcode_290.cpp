/****************************************************
 *** Problem Title : 290. Word Pattern
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/word-pattern/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
      map<char, string> mp;
      map<string, char> mp2;
      s += " ";
      string save = s;
        
      for (int i = 0; i < pattern.length(); i++) {
        int pos = s.find(" ");
        if (pos == -1) 
          return false;

        string word = s.substr(0, pos);
        if (mp.count(pattern[i]) == 0 && mp2.count(word) == 0)
          mp[pattern[i]] = word;
        s.erase(0, pos + 1);
      }

      string test = "";
      for (auto c : pattern) {
        test += mp[c];
        test += " ";
      }

      return (test == save);
    }
};
