//https://leetcode.com/problems/merge-two-sorted-lists/

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1 && !list2)
        return NULL;
    ListNode* list = new ListNode();
    ListNode* temp = list;
    while(list1 || list2){
        if(!list1 || (list2 && list1->val > list2->val)){
            temp->val = list2->val;
            list2 = list2->next;
        }else if(!list2 || (list1 && list1->val <= list2->val)){
            temp->val = list1->val;
            list1 = list1->next;
        }            
        if(list1 || list2){
            temp->next = new ListNode();
            temp = temp->next;
        }
    }
    return list;
}

int main(){

    return 0;
}
