/****************************************************
 *** Problem Number : 101. Symmetric Tree
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/symmetric-tree/description/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  bool Mirror(TreeNode *l, TreeNode *r) {
    if (!l && !r) return true;
    else if (!l || !r) return false;
    return (l->val == r->val) ? Mirror(l->left, r->right) && Mirror(l->right , r->left) : false;
  }
public:
    bool isSymmetric(TreeNode* root) {
      if (!root)
        return true;
      return Mirror(root->left, root->right);
    }
};