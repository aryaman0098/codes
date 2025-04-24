/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newNode = new ListNode();
        ListNode* head = newNode;
        int carry = 0, sum;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr && l2 != nullptr) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if(l2 == nullptr) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            newNode->next = new ListNode(sum);
            newNode = newNode->next;
        }
        if(carry > 0) newNode->next = new ListNode(carry);
        return head->next;
    }
};
// @lc code=end

