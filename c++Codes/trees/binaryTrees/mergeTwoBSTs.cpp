#include <bits/stdc++.h>
#include "binarySearchTreeTemp.h"

using namespace std;


void inorderArray(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    inorderArray(root->left, v);
    v.push_back(root->key);
    inorderArray(root->right, v);
}

void merge(vector<int> &v1, vector<int> &v2, vector<int> &v3){
    int c1 = 0, c2 = 0;
    while(c1 < v1.size() && c2 < v2.size()){
        if(v1[c1] <= v2[c2]){
            v3.push_back(v1[c1]);
            c1++;
        }else{
            v3.push_back(v2[c2]);
            c2++;
        }
    }
    if(c1 < v1.size()){
        while(c1 < v1.size()){
            v3.push_back(v1[c1]);
            c1++;
        }
    }else if(c2 < v2.size()){
        while(c2 < v2.size()){
            v3.push_back(v2[c2]);
            c2++;
        }
    }
}

void printList(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

Node* constructTree(vector<int> v, int low, int high){
    if(low > high){
        return NULL;
    }
    int mid = (high + low) / 2;
    Node* root = newNode(v[mid]);
    root->left = constructTree(v, low, mid - 1);
    root->right = constructTree(v, mid + 1, high);
    return root;
}

int main(){
    Node* root1 = NULL; 
    Node* root2 = NULL;
    root1 = insert(root1, 7);
    root1 = insert(root1, 5);
    root1 = insert(root1, 3);
    root1 = insert(root1, 11);
    root1 = insert(root1, 9);
    root1 = insert(root1, 13);
    root2 = insert(root2, 6);
    root2 = insert(root2, 2);
    root2 = insert(root2, 0);
    root2 = insert(root2, 4);
    root2 = insert(root2, 8);
    root2 = insert(root2, 10);
    vector<int> v1, v2, v3;
    inorderArray(root1, v1);
    inorderArray(root2, v2);
    merge(v1, v2, v3);
    Node* root = constructTree(v3, 0, v3.size() - 1);
    inOrder(root);
    cout<<"\n";
}