#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        bool pFound = false, qFound = false;

        function<TreeNode*(TreeNode*, TreeNode*, TreeNode*)> lca =
            [&](TreeNode* root, TreeNode* p, TreeNode* q) {
                if (root == NULL)
                    return root;
                if (root->val == p->val) {
                    pFound = true;
                    return root;
                }
                if (root->val == q->val) {
                    qFound = true;
                    return root;
                }
                TreeNode* left = lca(root->left, p, q);
                TreeNode* right = lca(root->right, p, q);
                if (!left)
                    return right;
                else if (!right)
                    return left;
                else
                    return root;
            };

        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root,
                                                       TreeNode* target) {
            if (root == NULL)
                return;
            if (root == target) {
                if (target == q)
                    qFound = true;
                if (target == p)
                    pFound = true;
            }
            dfs(root->left, target);
            dfs(root->right, target);
        };

        TreeNode* ans = lca(root, p, q);
        if (ans == p) {
            dfs(p, q);
        }
        if (ans == q) {
            dfs(q, p);
        }
        return (pFound && qFound) ? ans : NULL;
    }
};