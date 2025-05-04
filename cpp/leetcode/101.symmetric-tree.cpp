/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start

// Definition for a binary tree node.
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
    bool checkChilds(TreeNode* lc, TreeNode* rc) {
        if(lc == nullptr && rc == nullptr) return true;
        if((lc == nullptr && rc != nullptr) || (lc != nullptr && rc == nullptr)) return false;
        else {
            if(lc->val != rc->val) return false;
            return checkChilds(lc->left, rc->right) && checkChilds(lc->right, lc->left);
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        return checkChilds(root->left, root->right);
    }
};
// @lc code=end

