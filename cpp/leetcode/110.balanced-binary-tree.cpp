/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
      function<int(TreeNode* root)> height = [&](TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
      };
      if(root == nullptr) return true;
      return abs(height(root->right) - height(root->left) <= 1) &&
            isBalanced(root->right) && isBalanced(root->left);
    }
};
// @lc code=end

