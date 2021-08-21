#include<bits/stdc++.h>
#include "linkedlisttemp.h"

using namespace std;

void deleteNode(Node** head, Node* temp){
    Node* temp1 = *head;
    while(temp1 != NULL){
        if(temp1->next == temp){
            temp1->next = temp->next;
            delete(temp);
            break; 
        }
        temp1 = temp1->next;
    }
}

void removeDuplicate(Node** head){
    Node* temp = *head;
    while(temp != NULL){
        if(temp->next != NULL && temp->key == temp->next->key){
            deleteNode(head, temp->next);
            continue;
        }
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 2);
    add(&head, 2);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    add(&head, 5);
    add(&head, 6);
    printList(head);
    removeDuplicate(&head);
    printList(head);
}