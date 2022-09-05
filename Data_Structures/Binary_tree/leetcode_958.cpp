// 958. Check Completeness of a Binary Tree

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>
using namespace std;

//  Definition for a binary tree node.
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        bool no_more_allowed = false;
        
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            
            if (cur->left) {
                if (no_more_allowed)
                    return 0;
                q.push(cur->left);
            } else 
                no_more_allowed = true;
               
            if (cur->right) {
                if (no_more_allowed)
                   return 0;
                q.push(cur->right);
            } else
                no_more_allowed = true;
        }
        return 1;
    }
};