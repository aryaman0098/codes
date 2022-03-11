//https://leetcode.com/problems/partition-list/

#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* partition(ListNode* head, int x) {
    ListNode* before = new ListNode(0);
    ListNode* after = new ListNode(0);
    ListNode* temp1 = before;
    ListNode* temp2 = after;
    while(head){
        if(head->val < x){
            temp1->next = new ListNode(head->val);
            temp1 = temp1->next;
        }else{
            temp2->next = new ListNode(head->val);
            temp2 = temp2->next;
        }
    }
    temp2->next = NULL;
    temp1->next = after->next;
    return before->next;
}

int main(){

    return 0;
}
