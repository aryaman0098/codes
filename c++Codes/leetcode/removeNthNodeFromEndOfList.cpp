//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<bits/stdc++.h>

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp1 = head, *temp2 = head;
    while(n--)
        temp2 = temp2->next;
    if(!temp2)
        return head->next;
    while(temp2->next){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp1->next->next;
    return head; 
}

int main(){

    return 0;
}
