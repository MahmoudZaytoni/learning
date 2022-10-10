/****************************************************
 *** Problem Number : 823. Binary Trees With Factors
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/binary-trees-with-factors/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
class Solution {
  unordered_set<int> hash_set;
  unordered_map<int,ll> memory;

  ll cnt_trees(int value) {
    if (memory.count(value))
      return memory[value];

    ll cnt = 1;
    for (auto it : hash_set) {
      if (value % it == 0 && hash_set.count(value / it)) {
        auto sub_trees = (cnt_trees(it) * cnt_trees(value/it)) % mod;
        cnt += sub_trees;
        cnt %= mod;
      }
    }
    return memory[value] = cnt;
  }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
      hash_set.insert(arr.begin(), arr.end());

      int sum = 0;
      for (auto x : hash_set) {
        sum += cnt_trees(x);
        sum %= mod;
      }
      return sum;
    }
};