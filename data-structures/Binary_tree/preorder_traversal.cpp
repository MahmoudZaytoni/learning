/****************************************************
 *** Problem title  : 144. Binary Tree Preorder Traversal
 *** Diffculty      :  Easy
 *** URL            : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
  vector<int> res;

  void traverse(TreeNode* root) {
    if (!root)
      return;
      
    res.push_back(root->val);
    traverse(root->left);
    traverse(root->right);
  }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};