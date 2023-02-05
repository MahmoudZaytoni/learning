/****************************************************
 *** Problem Title  : 438. Find All Anagrams in a String
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/find-all-anagrams-in-a-string/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      if (p.size() > s.size())
        return {};

      vector<int> freq1(26), freq2(26);
      for (int i = 0; i < p.size(); i++)
        freq1[p[i]-'a']++, freq2[s[i]-'a']++;
      
      int len1 = s.size(), len2 = p.size();
      vector<int> res;
      for (int i = 0; i + len2 < len1; i++) {
        if (freq1 == freq2)
          res.push_back(i);
        freq2[s[i]-'a']--;
        freq2[s[i+len2]-'a']++;
      }
      if (freq1 == freq2)
        res.push_back(len1 - len2);
      return res;
    }
};