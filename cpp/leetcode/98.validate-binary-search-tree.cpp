/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*, TreeNode*)> helper =
            [&](TreeNode* root, TreeNode* min, TreeNode* max) {
                if (root == nullptr)
                    return true;
                if ((min != nullptr && min->val >= root->val) ||
                    (max != nullptr && max->val <= root->val))
                    return false;
                return helper(root->left, min, root) &&
                       helper(root->right, root, max);
            };
        return helper(root, nullptr, nullptr);
    }
};
// @lc code=end

