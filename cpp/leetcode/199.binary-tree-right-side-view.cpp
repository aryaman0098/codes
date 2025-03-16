/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void getLevelWiseNodes(TreeNode* root, vector<vector<int>> &v, int level) {
        v[level].push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            return;
        }
        if(level == v.size() - 1) {
            v.push_back({});
        }
        if(root->left == nullptr) {
            getLevelWiseNodes(root->right, v, level + 1);
        }else if(root->right == nullptr) {
            getLevelWiseNodes(root->left, v, level + 1);
        } else {
            getLevelWiseNodes(root->right, v, level + 1);
            getLevelWiseNodes(root->left, v, level + 1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> nodesAtLevels;
        nodesAtLevels.push_back({});
        getLevelWiseNodes(root, nodesAtLevels, 0);
        vector<int> ans;
        for(auto c: nodesAtLevels) {
            ans.push_back(c[0]);
        }
        return ans;
    }
};
// @lc code=end

