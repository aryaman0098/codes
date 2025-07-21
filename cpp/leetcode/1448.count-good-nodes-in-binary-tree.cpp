/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        int count = 0;
        function<void(TreeNode*, int)> helper = [&](TreeNode* root,
                                                    int maxTillNow) {
            if (root == nullptr)
                return;
            if (root->val >= maxTillNow)
                count += 1;
            helper(root->left, max(maxTillNow, root->val));
            helper(root->right, max(maxTillNow, root->val));
            return;
        };
        helper(root, root->val);
        return count;
    }
};
// @lc code=end

