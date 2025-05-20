/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow = head, *fast = head->next;
        while(slow != fast) {
            if(!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end

