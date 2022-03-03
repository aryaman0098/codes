//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return head;
    if(!head->next) return head;
    ListNode** temp = &head;
    while(*temp){
        if((*temp)->next && (*temp)->val == (*temp)->next->val){
            ListNode* temp1 = *temp;
            while(temp1 && (*temp)->val == temp1->val)
                temp1 = temp1->next;
            *temp = temp1;
        }else{
            temp = &((*temp)->next);
        }
    }
    return head;
}

int main(){

    return 0;
}
