//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

#include<bits/stdc++.h>

using namespace std;

/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

Node * mergeKLists(Node *arr[], int K){
    priority_queue<int, vector<int>, greater<int> > pq;
    Node* temp;
    for(int i = 0; i < K; i++){
        temp = arr[i];
        while(temp){
            pq.push(temp->data);
            temp = temp->next;
        }
    }
    Node* ans = new Node(pq.top());
    temp = ans;
    pq.pop();
    while(!pq.empty()){
        temp->next = new Node(pq.top());
        pq.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return ans;
}

int main(){

    return 0;
}
