#include <bits/stdc++.h>
#include "binarySearchTreeTemp.h"

using namespace std;

int leastCommonAncestor(Node* root, int n1, int n2){
    if(n1 <= root->key && n2 >= root->key){
        return root->key;
    }else if(n1 < root->key && n2 < root-> key){
        return leastCommonAncestor(root->left, n1, n2);
    }else if(n1 > root->key && n2 > root-> key){
        return leastCommonAncestor(root->right, n1, n2);
    }else if(n1 == root->key && n2 > root->key){
        return root->key;
    }else if(n1 < root->key && n2 == root->key){
        return root->key;
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 12);
    cout<<leastCommonAncestor(root, 2, 12);
    cout<<"\n";
} 