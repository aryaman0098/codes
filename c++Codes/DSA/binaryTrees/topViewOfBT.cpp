//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<bits/stdc++.h>

using namespace std;

vector<int> topView(Node *root){
    map<int, int> m;
    queue<pair<Node*, int> > q;
    q.push(root, 0);
    int level = 0;
    m[level] = root->data;
    while(!q.empty()){
        Node* temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if(!m[h]){
            m[h] = t->data;
        }
        if(t->left){
            q.push({t->left, h - 1});
        }
        if(t->right){
            q.push({t->right, h + 1});
        }
    }
    vector<int> ans;
    for(auto x : m){
        ans.push_back(x.second);
    }
    return ans;
}

int main(){

    return 0;
}
