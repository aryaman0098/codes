/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> count = [&](TreeNode* root) {
            if (root == nullptr)
                return 0;
            int left = count(root->left);
            int right = count(root->right);
            ans = max(ans, max(1 + max(right, left), 1 + right + left));
            return 1 + max(right, left);
        };
        count(root);
        return ans - 1;
    }
};
// @lc code=end

