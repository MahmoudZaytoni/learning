/****************************************************
 *** Problem title  : 134. Gas Station
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/gas-station/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> prefix(n);
        
        int idx = -1;
        for (int i = 0; i < n; i++)
          prefix[i] = gas[i] - cost[i];

        for (int i = 1; i < n; i++) {
          prefix[i] += prefix[i-1];
        }
        
        if (prefix.back() >= 0)
          return min_element(prefix.begin(), prefix.end()) - prefix.begin();
        return -1;
    }
};