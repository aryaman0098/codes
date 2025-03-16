/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    void zigZagTraversal(TreeNode* node, vector<vector<int>> &v, int level) {
        v[level].push_back(node->val);
        if(node->left == nullptr && node->right == nullptr) {
            return;
        }
        if(level == v.size() - 1) {
            v.push_back({});
        }
        if(node->left == nullptr) {
            zigZagTraversal(node->right, v, level + 1);
        } else if(node->right == nullptr) {
            zigZagTraversal(node->left, v, level + 1);
        } else {
            zigZagTraversal(node->left, v, level + 1);
            zigZagTraversal(node->right, v, level + 1);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        ans.push_back({});
        zigZagTraversal(root, ans, 0);
        for(int i  = 0; i < ans.size(); i++) {
            if(i % 2 != 0) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};
// @lc code=end

