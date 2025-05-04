/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int, int> u;
    int preorderIndex;

    TreeNode* constructTree(vector<int> preorder, int left, int right) {
        if(left > right) return nullptr;
        int rootValue = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(rootValue);
        root->left = constructTree(preorder, left, u[rootValue] - 1);
        root->right = constructTree(preorder, u[rootValue] + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            u[inorder[i]] = i;
        } 
        return constructTree(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end

