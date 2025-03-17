/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else if(root->right == nullptr && root->left == nullptr) {
            return 1;
        } else if(root->right == nullptr) {
            return 1 + maxDepth(root->left);
        } else if(root->left == nullptr) {
            return 1 + maxDepth(root->right);
        } else {
            return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
        }
    }
};
// @lc code=end

