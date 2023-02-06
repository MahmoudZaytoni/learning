/****************************************************
 *** Problem Title  : 230. Kth Smallest Element in a BST
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int &k) {
      if (k == 0)
        return -1;
      
      if (root->left) {
        int ans = kthSmallest(root->left, k);
        if (k == 0)
          return ans;
      }

      k--;
      if (k == 0)
        return root->val;
      
      if (root->right)
        return kthSmallest(root->right, k);
      return -1;
    }
};