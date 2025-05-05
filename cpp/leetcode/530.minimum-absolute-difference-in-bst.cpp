/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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

    TreeNode* prev;

    void getMin(TreeNode* root, int& ans) {
        if(root == nullptr) return;
        getMin(root->left, ans);
        if(prev != nullptr) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        getMin(root->right, ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        getMin(root, ans);
        return ans;
    }
};
// @lc code=end

