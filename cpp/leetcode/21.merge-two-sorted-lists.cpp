/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node = new ListNode();
        while(list1 && list2) {
            int val;
            if(list1->val < list2->val) {
                val = list1->val;
                list1 = list1->next;
            } else {
                val = list2->val;
                list2 = list2->next;
            }
            node->next = new ListNode(val);
            node = node->next;
        }
        while(list1) {
            node->next = new ListNode(list1->val);
            node = node->next;
            list1 = list1->next;
        }
        while(list2) {
            node->next = new ListNode(list2->val);
            node = node->next;
            list2 = list2->next;
        }
        return node->next;
    }
};
// @lc code=end

