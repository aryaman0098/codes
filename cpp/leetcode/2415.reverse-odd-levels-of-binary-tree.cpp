/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
private:
    void reverseLevelWise(TreeNode* root, int level) {
        if(root->left == nullptr && root->right == nullptr) {
            return;
        }
        if(level % 2 == 0) {
            int temp = root->right->val;
            root->right->val = root->left->val;
            root->left->val = temp;
        }
        reverseLevelWise(root->left, level + 1);
        reverseLevelWise(root->right, level + 1);
    }
public: 
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseLevelWise(root, 0);
        return root;
    }
};
// @lc code=end

