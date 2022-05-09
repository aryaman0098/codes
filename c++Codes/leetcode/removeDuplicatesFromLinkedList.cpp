//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode** temp = &head;
        while(*temp->next){
            if(*temp->val == *temp->next->val){
                ListNode* temp1 = *temp;
                while(temp1->next && *temp->val == temp1->val){
                    temp1 = temp1->next;
                }
                *temp->next = temp1;
            }else{
                *temp = *temp->next;
            }
        }
        return head;
    }
};

int main(){

    return 0;
}
