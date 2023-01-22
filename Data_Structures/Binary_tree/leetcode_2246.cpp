/****************************************************
 *** Problem Title : 2246. Longest Path With Different Adjacent Characters
 *** Diffculty      : Hard
 *** URL            : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


typedef vector<vector<int>> GRAPH;

class Solution {
  GRAPH tree;
  string s;
  int dfs(int cur, int parent) {
    int mx = 1, mx_child = 0;
    for (auto child : tree[cur]) {
      if (child == parent) continue;
      mx_child = dfs(child, cur);
      if (s[cur] != s[child])
        mx_child += 1;
    }
    return max(mx, mx_child);
  }
public:
  int longestPath(vector<int>& parent, string s) {
    this->s = s;
    tree = GRAPH(parent.size());
    for (int i = 1; i < parent.size(); i++) {
      tree[i].push_back(parent[i]);
      tree[parent[i]].push_back(i);
    }
    return dfs(0, -1);
  }
};