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
    int closestValue(TreeNode* root, double target) {
        double minDiff = DBL_MAX;
        int ans = INT_MAX;
        function<void(TreeNode*)> search = [&](TreeNode* root) {
            if (root == nullptr)
                return;
            double diff = abs(root->val - target);
            if (diff < minDiff || (diff == minDiff && root->val < ans)) {
                minDiff = diff;
                ans = root->val;
            }
            if (root->val > target)
                search(root->left);
            else if (root->val < target)
                search(root->right);
        };
        search(root);
        return ans;
    }
};