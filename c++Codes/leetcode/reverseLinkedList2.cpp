//https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) 
            return head;
        int counter = 1;
        ListNode* prev = head;
        ListNode* next = head;
        while(counter < left - 1){
            prev = prev->next;
            counter++;
        }
        ListNode* currL = (left != 1) ? prev->next : head;
        counter = 1;
        ListNode* currR;
        while(counter <= right){
            currR = next;
            next = next->next;
            counter++;
        }
        if(left != 1)
            prev->next = currR;
        ListNode* temp = currL;
        ListNode *p = NULL, *n = NULL;
        int l = right - left + 1;
        while(currL && l--){
            n = currL->next;
            currL->next = p;
            p = currL;
            currL = n;
        }
        temp->next =next;
        return (left != 1) ? head : currR;
    }
};

int main(){

    return 0;
}
