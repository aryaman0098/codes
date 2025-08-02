/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*, int)> helper = [&](TreeNode* root, int curr) {
            int n = curr * 10 + root->val;
            if(root->left == nullptr && root->right == nullptr) {
              sum += n;
              return;
            }
            if(root->left != nullptr) helper(root->left, n);
            if(root->right != nullptr) helper(root->right, n);
        };
        helper(root, 0);
        return sum;
    }
};
// @lc code=end

