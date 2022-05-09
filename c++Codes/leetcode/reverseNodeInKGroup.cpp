//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == NULL)
            return NULL;
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            temp = temp->next;
            n++
        }
        ListNode* curr = head, next = NULL, prev = NULL;
        int counter1 = 0, counter2 = 0;
        while(n >= k){
            prev = curr;
            while(counter1 < k){
                curr
            }
        }
    }

int main(){

    return 0;
}
