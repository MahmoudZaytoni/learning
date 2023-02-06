/****************************************************
 *** Problem Title  : 108. Convert Sorted Array to Binary Search Tree
 *** Diffculty      : Easy
 *** URL            : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* generate(vector<int>& nums, int l, int r) { 
      // l = left, r = right
      if (l > r)
        return nullptr;
      int mid = (l + r) / 2;
      TreeNode *root = new TreeNode(nums[mid]);
      root->left = generate(nums, l, mid-1);
      root->right = generate(nums, mid+1, r);
      return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return generate(nums, 0, (int)nums.size() - 1);
    }
};