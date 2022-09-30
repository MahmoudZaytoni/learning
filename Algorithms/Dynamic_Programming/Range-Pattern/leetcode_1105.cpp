/****************************************************
 *** Problem Number : 1105
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/filling-bookcase-shelves/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX];

int mnHight(vector<vector<int>> &books, int shelfWidth, int idx) {
  if (idx >= books.size())
    return 0;
  
  int &ret = memory[idx];
  if (ret != -1 ) return ret;

  ret = INT_MAX;
  int total_with = 0, mx_height = 0;
  for (int k = idx; k < books.size(); k++) {
    total_with += books[k][0];
    mx_height = max(mx_height, books[k][1]);

    if (total_with <= shelfWidth)
      ret = min(ret, mx_height + mnHight(books, shelfWidth, k + 1));
  }
  return ret;
}

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(memory, -1, sizeof(memory));
        return mnHight(books, shelfWidth, 0);
    }
};