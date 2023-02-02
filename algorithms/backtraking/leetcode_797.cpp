/****************************************************
 *** Problem Number : 797. All Paths From Source to Target
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/all-paths-from-source-to-target/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  void dfs(vector<vector<int>> &ans, vector<int> &curList, int node, vector<vector<int>> &graph) {
    curList.push_back(node);

    if (node == (int)graph.size() - 1) {
      ans.push_back(curList);
      return;
    }
    
    for (auto &child : graph[node]) {
      dfs(ans, curList, child, graph);
      curList.pop_back();
    }
  }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<vector<int>> ans;
      vector<int> curList;
      dfs(ans, curList, 0, graph);
      return ans;
    }
};