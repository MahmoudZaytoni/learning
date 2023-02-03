/****************************************************
 *** Problem Title  : 953. Verifying an Alien Dictionary
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/verifying-an-alien-dictionary/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
      vector<int> alien_to_normal(26);
      int idx = 0;
      for (auto ch : order)
        alien_to_normal[ch-'a'] = idx++;

      for (auto &word : words) {
        string temp = "";
        for (auto ch : word)
          temp += char(alien_to_normal[ch-'a']+'a');
        word = temp;
      }
      return is_sorted(words.begin(), words.end());
    }
};