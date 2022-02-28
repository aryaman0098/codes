//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include<bits/stdc++.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

unordered_map<int, vector<Node*>> u;

void join(Node* root, int level){
    u[level].push_back(root);
    if(root->left == NULL && root->right == NULL)
        return;
    level++;
    join(root->left, level);
    join(root->right, level);
}

Node* connect(Node* root) {
    if(root == NULL)
        return NULL;
    int level = 0;
    join(root, level);      
    for(auto i : u){
        for(int j = 0; j < i.second.size() - 1; j++){
            u[i.first][j]->next = u[i.first][j + 1];
        }
        u[i.first][u[i.first].size() - 1]->next = NULL;
    }
    return root;
}

int main(){

    return 0;
}
