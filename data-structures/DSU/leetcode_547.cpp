#include <bits/stdc++.h>
using namespace std;
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
  
    int solve() {
      int cnt = 0;
      for (int i = 0; i < root.size(); i++) {
         if (root[i] == i)
          cnt++;
      }
      return cnt;
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();
      UnionFind uf(isConnected.size());
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
          if (isConnected[i-1][j-1])
              uf.unionSet(i-1,j-1);
      }
      return uf.solve();
    }
};