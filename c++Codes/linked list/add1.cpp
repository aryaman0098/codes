#include<bits/stdc++.h>
#include "linkedlisttemp.h"

using namespace std;

void add1(Node* head){
    Node* temp = head;
    int c = 0;
    while(temp != NULL){
        c+=1;
        temp = temp->next;
    }
    int value = 0;
    while(head != NULL){
        value += head->key * (int)pow(10, c - 1);
        c--;
        head = head->next; 
    }
    value+=1;
    cout<<value<<"\n";
}

int  main(){
    Node* head = NULL;
    add(&head, 4);
    add(&head, 5);
    add(&head, 7);
    add(&head, 9);
    add1(head);
}