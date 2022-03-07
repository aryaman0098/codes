//https://leetcode.com/problems/rotate-list/

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

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || k == 0) return head;
    int n = 0;
    ListNode* temp = head;
    while(temp){
        n++;
        temp = temp->next;
    }
    k %= n;
    if(k == 0) return head;
    int i = n - k - 1;
    ListNode *m = head, *e = head, *h;
    while(e->next){
        e = e->next;
        if(i){
            m = m->next;
            i--;
        }
    }
    h = m->next;
    e->next = head;
    m->next = NULL;
    return h;
}

int main(){

    return 0;
}
