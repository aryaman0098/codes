#include <bits/stdc++.h>
#include "binarySearchTreeTemp.h"

using namespace std;

bool search(Node* root, int val){
    if(root == NULL){
        return false;
    }
    if(root->key == val){
        return true;
    }else if(root->key > val){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 5);
    inOrder(root);
    cout<<"\n";
    cout<<search(root, 8)<<"\n";
}