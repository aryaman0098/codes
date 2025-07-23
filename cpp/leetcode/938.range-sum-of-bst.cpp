/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        function<void(TreeNode*)> add = [&](TreeNode* root) {
            if (root == nullptr)
                return;
            sum += (low <= root->val && root->val <= high) ? root->val : 0;
            if (low <= root->val && root->val <= high) {
                add(root->left);
                add(root->right);
            } else if (root->val < low) {
                add(root->right);
            } else if (root->val > high) {
                add(root->left);
            }
        };
        add(root);
        return sum;
    }
};
// @lc code=end
