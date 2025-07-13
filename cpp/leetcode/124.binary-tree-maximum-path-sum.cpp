/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
      int ans = INT_MIN;
      function<int(TreeNode*)> getMaxPath = [&](TreeNode* root) {
        if(root == nullptr) return 0;
        int rightPathSum = getMaxPath(root->right);
        int leftPathSum = getMaxPath(root->left);
        ans = max(ans, max(root->val, max(root->val + leftPathSum + rightPathSum ,root->val + max(leftPathSum, rightPathSum))));
        return max(root->val, root->val + max(leftPathSum, rightPathSum));
      };
      getMaxPath(root);
      return ans;
    }
};
// @lc code=end

