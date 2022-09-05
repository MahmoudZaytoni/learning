// 103. Binary Tree Zigzag Level Order Traversal

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (!root)
            return result;
        
        deque<TreeNode*> dq;
        dq.push_back(root);

        int level = 0;
        bool forward_level = true;
        while (!dq.empty()) {
            int sz = dq.size();
            vector<int> v;
            result.push_back(v);
            while (sz--) {
                TreeNode *cur;
                if (forward_level) {
                    cur = dq.front();
                    dq.pop_front();

                    if (cur->left != nullptr)
                        dq.push_back(cur->left);
                    if (cur->right != nullptr)
                        dq.push_back(cur->right);
                } else {
                    cur = dq.back();
                    dq.pop_back();

                    if (cur->right != nullptr)
                        dq.push_front(cur->right);
                    if (cur->left != nullptr)
                        dq.push_front(cur->left);
                }
                result[level].push_back(cur->val);
            }
            level++;
            forward_level = !forward_level;
        }
        return result;
    }
};