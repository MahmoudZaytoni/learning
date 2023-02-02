/****************************************************
 *** Problem Number : 91
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/decode-ways/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];

int count(int idx, string &s) {
  if (idx == s.size())
    return 1;

  if (s[idx] == '0')
    return false;
  
  auto &ret = memory[idx];
  if (ret != -1)
    return ret;
  
  int choice1 = count(idx+1,s);
  int choice2 = 0;

  
  if (idx + 1 < s.size()) {
    int val = stoi(s.substr(idx,2));
    if (val <= 26 && val >= 1)
      choice2 = count(idx+2, s);
  }

  return ret = choice1 + choice2;
}

class Solution {
public:
    int numDecodings(string s) {
      memset(memory, -1, sizeof(memory));
      return count(0, s);
    }
};

int main()
{
  string str; cin >> str;
  Solution s;
  cout << s.numDecodings(str) << "\n";
  
  return 0;
}