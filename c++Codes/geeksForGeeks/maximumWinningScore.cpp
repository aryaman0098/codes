//https://practice.geeksforgeeks.org/problems/4ead9c3991a3822f578309e2232bc5415ac35cb9/1#

#include<bits/stdc++.h>

using namespace std;

//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
    
void maxScores(vector<long long> &p, Node* root, long long max){
    if(!root){
        p.push_back(max);
        return;
    }
    max *= root->data;
    maxScores(p, root->left, max);
    maxScores(p, root->right, max);
}

long long findMaxScore(Node* root){
    // Your code goes here
    vector<long long> p;
    long long max = 1;
    maxScores(p, root, max);
    return *max_element(p.begin(), p.end());
}

int main(){

    return 0;
}
