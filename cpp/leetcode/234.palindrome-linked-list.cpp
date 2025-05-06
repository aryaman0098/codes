/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
private:
    ListNode* getFirstHalfEnd(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode *head) {
        if(head == nullptr) return true;
        ListNode *firstHalfEnd = getFirstHalfEnd(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);
        ListNode *p1 = head, *p2 = secondHalfStart;
        bool result = true;
        while(result && p2) {
            if(p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }
};
// @lc code=end

