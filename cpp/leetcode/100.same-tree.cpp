/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    void preOrderTraversal(TreeNode* node, vector<int> &v) {
        v.push_back(node->val);
        if(node->left == nullptr && node->right) {
            return;
        }
        if(node->left != nullptr) {
            preOrderTraversal(node->left, v);
        }
        if(node->right != nullptr) {
            preOrderTraversal(node->right, v);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1, v2;
        preOrderTraversal(p, v1);
        preOrderTraversal(q, v2);
        if(v1.size() != v2.size()) {
            return false;
        }
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};
// @lc code=end

