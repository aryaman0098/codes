/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    unordered_map<int, vector<int>> u;

    void getNodeValuesAtEachLevel(TreeNode* root, int level) {
        if(u.find(level) == u.end()) u[level] = {};
        u[level].push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            return;
        }
        if(root->left == nullptr) {
            getNodeValuesAtEachLevel(root->right, level + 1);
        } else if(root->right == nullptr) {
            getNodeValuesAtEachLevel(root->left, level + 1);
        } else {
            getNodeValuesAtEachLevel(root->left, level + 1);
            getNodeValuesAtEachLevel(root->right, level + 1);
        }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        getNodeValuesAtEachLevel(root, 0);
        vector<double> ans (u.size(), 0.0);
        for(auto c: u) {
            double sum = 0.0;
            for(auto d: c.second) {
                sum += d;
            }
            ans[c.first] = (sum * 1.0) / (c.second.size() * 1.0);
        }
        return ans; 
    }
};
// @lc code=end

