#ifndef linkedlisttemp
#define linkedlisttemp

class Node{
    public:
        int key;
        Node* next;
};


void add(Node** head, int data);

void remove(Node** head, int data);

void printList(Node* head);

#endif