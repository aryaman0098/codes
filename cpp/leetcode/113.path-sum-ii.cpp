/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start

//Definition for a binary tree node.
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
    void getPaths(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> container) {
        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == targetSum) {
                container.push_back(root->val);
                ans.push_back(container);
            }
            return;
        }
        container.push_back(root->val);
        getPaths(root->left, targetSum - root->val, ans, container);
        getPaths(root->right, targetSum - root->val, ans, container);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        getPaths(root, targetSum, ans, {});
        return ans;
    }
};
// @lc code=end

