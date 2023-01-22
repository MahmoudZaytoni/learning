/****************************************************
 *** Problem Number : 399. Evaluate Division
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/evaluate-division/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


#define psd pair<string, double>
class UnionFind {
public:
  map<string, psd> root;

  psd find(string x) {
    if (!root.count(x))
      root[x] = {x, 1.0};
    
    if (x == root[x].first)
      return root[x];
    
    psd parent = find(root[x].first);
    root[x].first   = parent.first;
    root[x].second *= parent.second;
    return {parent.first, root[x].second};
  }

  void UnionSet(string x, string y, double value) {
    psd rootX = find(x);
    psd rootY = find(y);

    if (rootX.first == rootY.first) // if they in Same Component
      return;
    
    root[rootY.first].first = rootX.first;
    root[rootY.first].second = rootX.second / (rootY.second * value);
  }

  bool connected(string x, string y) {
    return find(x) == find(y);
  }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      UnionFind uf;
      int idx = 0;

      for (auto &p : equations)
        uf.UnionSet(p[0], p[1], values[idx++]);
      
      vector<double> res;

      for (auto &p : queries) {
        string x = p[0], y = p[1];
        double ans = -1.0;
        if (uf.root.count(x) && uf.root.count(y)) {
          psd rootX = uf.find(x);
          psd rootY = uf.find(y);

          if (rootX.first == rootY.first) {
            ans = rootX.second / rootY.second;
          }
        }

        res.push_back(ans);
      }

      return res;
    }
};