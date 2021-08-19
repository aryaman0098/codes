#include<bits/stdc++.h>
#include "binarySearchTreeTemp.h"

using namespace std;

Node* newNode(int data){
        Node* temp = new Node();
        temp->key = data;
        temp->right = NULL;
        temp->left = NULL;
        return temp;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return newNode(data);
    }

    if(data < root->key){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);
}