/****************************************************
 *** Problem Title  : 121. Best Time to Buy and Sell Stock
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Get the number of prices in the vector
        int numPrices = prices.size();
      
        // Initialize variables to keep track of the minimum price seen so far,
        // and the maximum profit that can be obtained by selling at a higher price
        // after buying at the minimum price
        int minPrice = prices[0];
        int maxProfit = 0;
      
        // Iterate through the vector of prices
        for (int i = 1; i < numPrices; i++) {
            // If the current price is lower than the minimum price seen so far,
            // update the minimum price
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Otherwise, if the current price minus the minimum price is greater
            // than the current maximum profit, update the maximum profit
            else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
      
        // Return the maximum profit that can be obtained
        return maxProfit;
    }
};
