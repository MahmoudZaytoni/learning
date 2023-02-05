/****************************************************
 *** Problem Title  : 826. Most Profit Assigning Work
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/most-profit-assigning-work/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
      int n = difficulty.size();
      vector<pair<int,int>> profit_difficulty(n);
      for (int i = 0; i < n; i++)
        profit_difficulty[i] = {profit[i], difficulty[i]};
      
      sort(profit_difficulty.rbegin(), profit_difficulty.rend());
      sort(worker.rbegin(), worker.rend());
      int mxProfit = 0 , idx = 0;
      for (int i = 0; i < worker.size() && idx < n; i++) {
        int dif = profit_difficulty[idx].second;
        while (idx + 1< n && dif > worker[i]) {
          dif = profit_difficulty[++idx].second;
        }
        if (worker[i] >= dif)
          mxProfit += profit_difficulty[idx].first;
      }
      return mxProfit;
    }
};