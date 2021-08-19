#include<bits/stdc++.h>
#include "binarySearchTreeTemp.h"

using namespace std;

bool isAscending(vector<int> v){
    if(v.size() == 0){
        return true;
    }
    int flag = 1;
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i + 1]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        return true;
    }else{
        return false;
    }
}

void inorderArray(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    inorderArray(root->left, v);
    v.push_back(root->key);
    inorderArray(root->right, v);
}

int largestBST(Node* root){
    vector<int> v;
    inorderArray(root, v);
    if(isAscending(v)){
        return v.size();
    }
    int largestLeft = 0;
    int largestRight = 0;
    largestLeft = largestBST(root->left);
    largestRight = largestBST(root->right);
    if(largestLeft >= largestRight){
        return largestLeft;
    }else{
        return largestRight;
    }
}

int main(){
    Node* root1 = new Node();
    Node* root2 = new Node();
    Node* root3 = new Node();
    Node* root4 = new Node();
    Node* root5 = new Node();
    Node* root6 = new Node();
    Node* root7 = new Node();
    root1->key = 4;
    root2->key = 5;
    root3->key = 2;
    root4->key = 7;
    root5->key = 6;
    root6->key = 3;
    root7->key = 1;
    root1->left = root2;
    root1->right = root6;
    root2->left = root3;
    root2->right = root4;
    root3->left = root3->right = NULL;
    root4->left = root5;
    root4->right = NULL;
    root5->left = root5->right = NULL;
    root6->left = NULL;
    root6->right = root7;
    root7->right = root7->left = NULL;
    cout<<largestBST(root1)<<"\n";
}