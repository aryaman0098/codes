/*
 * @lc app=leetcode id=3063 lang=cpp
 *
 * [3063] Linked List Frequency
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> u;
        while(head != nullptr) {
            if(u.find(head->val) == u.end()) u[head->val] = 0;
            u[head->val] +=1;
            head = head->next;
        }
        ListNode* ans = nullptr;
        ListNode* tail = nullptr;
        for(auto c: u) {
            ListNode* node = new ListNode(c.second);
            if(head == nullptr) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};
// @lc code=end

