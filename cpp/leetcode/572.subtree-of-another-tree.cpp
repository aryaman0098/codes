/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        function<bool(TreeNode*, TreeNode*)> areIdentical = [&](TreeNode* r1,
                                                                TreeNode* r2) {
            if (!r1 && !r2)
                return true;
            if (!r1 || !r2)
                return false;
            return r1->val == r2->val && areIdentical(r1->left, r2->left) &&
                   areIdentical(r1->right, r2->right);
        };
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node)
                return false;
            if (areIdentical(node, subRoot))
                return true;
            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }
};
// @lc code=end

