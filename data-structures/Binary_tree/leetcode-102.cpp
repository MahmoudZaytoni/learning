/****************************************************
 *** Problem Number : 102. Binary Tree Level Order Traversal
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (!root)
        return {};
      queue<TreeNode*> q;
      q.push(root);
      vector<vector<int>> res;
      for (int sz = 1; !q.empty(); sz = q.size()) {
        vector<int> level;
        while (sz--) {
          TreeNode* cur = q.front();
          q.pop();

          level.push_back(cur->val);

          if (cur->left)
            q.push(cur->left);
          if (cur->right)
            q.push(cur->right);
        }
        res.push_back(level);
      }
      return res;
    }
};