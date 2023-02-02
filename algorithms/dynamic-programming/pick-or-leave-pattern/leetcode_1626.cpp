/****************************************************
 *** Problem Number : 1626. Best Team With No Conflicts
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/best-team-with-no-conflicts/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 2;
int memory[MAX][MAX];
class Solution {
  int n;
  int mxScore(int idx, int prv, vector<pair<int,int>> &age_score) {
    if (idx >= n)
      return 0;
    
    int &ret = memory[idx][prv+1];
    if (ret != -1)
      return ret;
    
    int choice1 = mxScore(idx+1, prv, age_score);
    int choice2 = 0;
    if (prv == -1 || age_score[idx].second >= age_score[prv].second)
      choice2 = age_score[idx].second + mxScore(idx+1, idx, age_score);
    return ret = max(choice1, choice2);
  }
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    this->n = (int)scores.size();
    vector<pair<int,int>> age_score(n);
    for (int i = 0; i < n; i++)
      age_score[i] = make_pair(ages[i], scores[i]);
    
    sort(age_score.begin(), age_score.end());
    memset(memory, -1, sizeof(memory));
    return mxScore(0, -1, age_score);
  }
};