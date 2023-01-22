/****************************************************
 *** Problem Title  :  1443. Minimum Time to Collect All Apples in a Tree

 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>>  GRAPH;

class Solution {
  int dfs(int cur, int parent,  GRAPH &graph, vector<bool> &hasApple) {
    int totalTime = 0, childTime = 0;
    for (auto node : graph[cur]) {
        if (node == parent) continue;
        childTime = dfs(node,cur, graph, hasApple);
        if (childTime || hasApple[node])
          totalTime += childTime + 1;
    }
    return totalTime;
  }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        GRAPH graph(n);
        for (int i = 0; i < edges.size(); i++) {
          graph[edges[i][0]].push_back(edges[i][1]);
          graph[edges[i][1]].push_back(edges[i][0]);
        }

        int count = dfs(0, -1, graph, hasApple);
        return 2 * count;
    }
};