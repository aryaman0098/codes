//Problem -> https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int v1, v2;
        int sum;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while (l1 != nullptr || l2 != nullptr){
            v1 = 0;
            v2 = 0;
            if (l1 != nullptr){
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                v2 = l2->val;
                l2 = l2->next;
            }
            sum = v1 + v2 + carry;
            carry = 0;
            if (sum >= 10){
                sum = sum % 10;
                carry = 1;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;
        }
        if (carry != 0){
            temp->next = new ListNode(carry);
        }
        return ans->next;
    }
};