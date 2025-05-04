/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
//Definition for a binary tree node.
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
    priority_queue<int, vector<int>> pq;
    int k;
    void reverseInorderTraversal(TreeNode* root) {
        if(root == nullptr) return;
        reverseInorderTraversal(root->right);
        pq.push(root->val);
        if(pq.size() > k) pq.pop();
        cout<<pq.top()<<endl;
        reverseInorderTraversal(root->left);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        reverseInorderTraversal(root);
        return pq.top();
    }
};
// @lc code=end

