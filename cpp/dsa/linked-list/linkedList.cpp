#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

Node* insertAtStart(Node* head, int val);
Node* insertAnywhere(Node* head, int val, int n);
void insertAtEnd(Node* head, int val);
void traverseLinkedList(Node* head);
void reverseLinkedList(Node** head);

Node* insertAtStart(Node* head, int val) {
  Node* node = new Node(val);
  node->next = head; 
  return node;
}

Node* insertAnywhere(
  Node* head, 
  int val, 
  int n
) {
  if(n <= 0) {
    cout<<"Invalid position"<<endl;
    return head;
  }
  if(n == 1) {
    return insertAtStart(head, val);
  }
  Node* curr = head;
  while(--n > 1) {
    curr = curr->next;
    if(curr == nullptr) {
      insertAtEnd(head, val);
      return head;
    }
  }

  Node* node = new Node(val);
  node->next = curr->next;
  curr->next = node;
  return head;    
}

void insertAtEnd(Node* head, int val) {
  Node* curr = head;
  while(curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = new Node(val);
}

void traverseLinkedList(Node *head) {
  while(head != nullptr) {
    cout<<"["<<head->data<<"]->";
    head = head->next;
  }
  cout<<"null"<<endl;
}

void reverseLinkedList(Node** head) {
  Node* curr = *head;
  Node* prev = nullptr;
  Node* next;
  while(curr!= nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

int main() {
  Node* head = new Node(0);
  head = insertAtStart(head, 1);
  head = insertAtStart(head, 2);
  head = insertAtStart(head, 3);
  head = insertAtStart(head, 4);
  head = insertAtStart(head, 5);
  head = insertAtStart(head, 6);
  head = insertAnywhere(head, -1, 5);
  traverseLinkedList(head);
  reverseLinkedList(&head);
  traverseLinkedList(head);
  return 0;
}
