/****************************************************
 *** Problem Number : 309
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 *****************************************************/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000 + 1;
int memory[MAX_N][2][3]; 

enum {
  NOTHING = 0, SELL = 1, BUY = 2
};

class Solution {

  int mx(vector<int> &prices,int idx, int have_stock, int last_transaction) {
    if (idx >= prices.size())
      return 0;
    
    auto &ret = memory[idx][have_stock][last_transaction];
    if (ret != -1) return ret;

    int cooldown = mx(prices, idx + 1, have_stock, NOTHING);
    int buy = 0, sell = 0;
    if (have_stock)
      sell = prices[idx] + mx(prices, idx + 1, 0, SELL);
    else if (last_transaction != SELL)
      buy = -prices[idx] + mx(prices, idx + 1, 1, BUY);

    return ret = max(cooldown, max(sell, buy));
  }

public:
    int maxProfit(vector<int>& prices) {

      memset(memory, -1, sizeof(memory));
      return mx(prices, 0, 0, NOTHING);
    }
};