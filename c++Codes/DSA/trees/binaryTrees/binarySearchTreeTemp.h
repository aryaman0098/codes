#ifndef binarySearchTreeTemp
#define binarySearchTreeTemp

class Node{
    public:
        int key;
        Node* right;
        Node* left;
};

Node* newNode(int data);

Node* insert(Node* root, int data);

void inOrder(Node* root);

#endif