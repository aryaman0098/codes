#include<bits/stdc++.h>
#include "linkedlisttemp.h"

using namespace std;


void add(Node** head, int data){
    Node* temp = new Node();
    temp->key = data;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    Node* temp1 = *head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }

    temp1->next = temp;
    return;
}

void remove(Node** head, int data){
    if(*head == NULL){
        return;
    }else if((*head)->key == data){
        Node* temp = *head;
        *head = (*head)->next;
        delete(temp);
        return;
    }
    Node* temp = *head;
    while((temp->next)->key != data){
        temp = temp->next;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
    return;
}

void printList(Node* head){
    while(head!= NULL){
        cout<<head->key<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
    return;
}
