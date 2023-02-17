/****************************************************
 *** Problem Title  : 783. Minimum Distance Between BST Nodes
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/minimum-distance-between-bst-nodes/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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
      void DFS(TreeNode* root, int &prv, int &cur,int &res) {
        if (root->left) {
          DFS(root->left,prv, cur, res);
        }

        cur = root->val;
        if (prv != -1)
          res = min(res, cur - prv);
        prv = cur;

        if (root->right) {
          DFS(root->right, prv, cur, res);
        }
    }

    int minDiffInBST(TreeNode* root) {
      int res = INT_MAX, prv = -1, cur = INT_MAX;
      DFS(root, prv, cur, res);
      return res;
    }
};