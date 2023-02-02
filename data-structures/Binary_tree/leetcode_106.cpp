/****************************************************
 *** Problem Number : 106. Construct Binary Tree from Inorder and Postorder Traversal
 *** Diffculty      : Medium
 *** URL            : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*****************************************************/
#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx) {
      if (start > end)
        return nullptr;
      int data = postorder[idx--];
      TreeNode *root = new TreeNode(data);
      for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == data) {
          if (i < end)
            root->right = build(inorder, postorder, i+1, end, idx);
          if (start < i)
            root->left = build(inorder, postorder, start, i-1, idx);
        }
      }
      return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      n--;
      return build(inorder, postorder, 0, n,n);
    }
};
