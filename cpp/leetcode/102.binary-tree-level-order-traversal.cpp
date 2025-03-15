/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */


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
    void getNodeValuesAtEachLevel(TreeNode* root, vector<vector<int>> & ans, int level) {
        ans[level].insert(ans[level].begin(), root->val);
        if(root->left == nullptr && root->right == nullptr) {
            return;
        }
        if(level == ans.size() - 1) {
            ans.push_back({});
        }
        if(root->right == nullptr) {
            getNodeValuesAtEachLevel(root->left, ans, level + 1);
        } else if(root->left == nullptr) {
            getNodeValuesAtEachLevel(root->right, ans, level + 1);
        } else {
            getNodeValuesAtEachLevel(root->right, ans, level + 1);
            getNodeValuesAtEachLevel(root->left, ans, level + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        ans.push_back({});
        getNodeValuesAtEachLevel(root, ans, 0);
        return ans;
    }
};
// @lc code=end

