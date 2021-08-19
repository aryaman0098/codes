#include<bits/stdc++.h>
#include "linkedlisttemp.h"

using namespace std;

void reverse(Node** head){
    Node* prev = NULL;
    Node* curr = *head;
    Node* temp = curr;
    while(curr!=NULL){
        curr = curr->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    *head = prev;
    return;
}   


int main(){
    Node* head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    add(&head, 6);
    add(&head, 7);
    printList(head);
    reverse(&head);
    printList(head);
}