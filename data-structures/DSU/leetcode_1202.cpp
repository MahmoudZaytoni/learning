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

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = s.size();
      UnionFind uf(n);
      for (auto &pair : pairs)
        uf.unionSet(pair[0], pair[1]);
      
      unordered_map<int, vector<int>> m;
      for (int i = 0; i < n; i++)
        m[uf.find(i)].push_back(i);
      
      for (auto &p : m) {
        string ss = "";
        for (int idx : p.second)
          ss += s[idx];
        sort(ss.begin(), ss.end());

        int i = 0;
        for (int idx : p.second)
          s[idx] = ss[i++];
      }
      return s;
    }
};