/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p1 = dummy, *p2 = dummy;
        for (int i = 0; i <= n; i++) {
            p1 = p1->next;
        }
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return dummy->next;
    }
};
// @lc code=end

