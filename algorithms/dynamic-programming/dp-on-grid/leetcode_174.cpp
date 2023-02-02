/****************************************************
 *** Problem Number : 174. Dungeon Game
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/dungeon-game/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200 + 1;
const int OO = 1e8;
int memory[MAX][MAX];



int mnHealth(int r, int c, vector<vector<int>> &dungeon) {
  if (r >= dungeon.size())
    return OO;
  if (c >= dungeon[0].size())
    return OO;

  if (r + 1 == dungeon.size() && c + 1 == dungeon[0].size()) {
    if (dungeon[r][c] < 0)
      return 1 - dungeon[r][c];
    return 1;
  }

  int &ret = memory[r][c];
  if (ret != -1 ) return ret;

  int mnHealthMove = min(mnHealth(r, c+1, dungeon),mnHealth(r+1, c, dungeon));
  if (mnHealthMove <= dungeon[r][c])
    return ret = 1;
  return ret = mnHealthMove - dungeon[r][c];
}
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    memset(memory, -1, sizeof(memory));
    return mnHealth(0,0, dungeon);
  }
};