/****************************************************
 *** Problem Number : 567. Permutation in String
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/permutation-in-string/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if (s1.size() > s2.size()) // s2 should always bigger
        return false;
      
      int len1 = s1.size(), len2 = s2.size();
      vector<int> freq1(26), freq2(26); // freq of characters
      for (int i = 0; i < len1; i++)
        freq1[s1[i]-'a']++, freq2[s2[i]-'a']++;
      
      for (int start = 0; start + len1 < len2; start++) {
        if (freq1 == freq2)
          return true;
        freq2[s2[start]-'a']--;
        freq2[s2[start+len1] - 'a']++;
      }
      return freq1 == freq2;
    }
};