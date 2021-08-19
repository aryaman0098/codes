#include<bits/stdc++.h>
#include "linkedlisttemp.h"

using namespace std;

int sizeOfLLS(Node* head){
    int c = 0;
    while(head != NULL){
        c++;
        head = head->next;
    }
    return c;
}

void reverseInGivenSize(Node** head, int size){
    int c = sizeOfLLS(*head);
    if (size >= c){
        cout<<"Reverse the entire linked list\n";
        return;
    }
    Node* curr = *head;
    Node* temp1;
    Node* temp2;
    int t;
    while(c > size){
        temp1 = curr;
        temp2 = curr;
        for(int i = 0; i < size/2; i++){
            for(int j = 0; j < size - 2*i - 1; j++){
                temp2 = temp2->next;
            }
            t = temp1->key;
            temp1->key = temp2->key;
            temp2->key = t;
            temp1 = temp1->next;
            temp2 = temp1;
        }
        for (int i = 0; i < size; i++){
            curr = curr->next;
        }
        c = c - size;
    }
    if(c != 0){
        temp1 = curr;
        temp2 = curr;
        for(int i = 0; i < c/2; i++){
            for(int j = 0; j < c - 2*i - 1; j++){
                temp2 = temp2->next;
            }
            t = temp1->key;
            temp1->key = temp2->key;
            temp2->key = t;
            temp1 = temp1->next;
            temp2 = temp1;
        }
    }
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
    reverseInGivenSize(&head, 7);
    printList(head);
}