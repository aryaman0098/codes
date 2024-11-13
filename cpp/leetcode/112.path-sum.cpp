/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start

  // struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  // };

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if(root == nullptr) {
        return false;
      }
      if(
        root->val == targetSum && 
        (root->left == nullptr && root->right == nullptr)
      ){
        return true;
      }
      return 
        hasPathSum(root->left, targetSum - root->val) || 
        hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end

