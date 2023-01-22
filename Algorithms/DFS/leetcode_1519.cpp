/****************************************************
 *** Problem Title  : 1519. Number of Nodes in the Sub-Tree With the Same Label

 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
class Solution {
  GRAPH tree;
  vector<int> dfs(int cur, int parent, string &labels, vector<int> &res) {
    vector<int> colors(26);
    colors[labels[cur] - 'a'] = 1;
    for (auto child : tree[cur]) {
      if (child == parent) continue;
      vector<int> childColors = dfs(child, cur, labels, res);
      for (int i = 0; i < 26; i++)
        colors[i] += childColors[i];
    }
    res[cur] += colors[labels[cur] - 'a'];
    return colors;
  }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
      tree = GRAPH(n);
      for (auto &e : edges) {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
      }

      vector<int> res(n);
      dfs(0, -1, labels, res);
      return res;
    }
};