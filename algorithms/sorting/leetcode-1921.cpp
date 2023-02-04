/****************************************************
 *** Problem Title  : 1921. Eliminate Maximum Number of Monsters
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
      int killed = 0, n = dist.size();
      vector<double> arrival_time(n);
      for (int i = 0; i < n; i++)
        arrival_time[i] = ((double)dist[i] / speed[i]);
      
      sort(arrival_time.begin(), arrival_time.end());

      for (int i = 0; i < n; i++)
        if (arrival_time[i] > i)
          killed++;
        else
          break;
      return killed;
    }
};