/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
private:
    unordered_map<Node*, Node*> u;
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* temp = head;
        Node* newNode =  new Node(head->val);
        Node* tail = newNode;
        u[head] = newNode;
        temp = temp->next;
        while(temp != nullptr) {
            Node* node = new Node(temp->val);
            tail->next = node;
            u[temp] = node;
            tail = node;
            temp = temp->next;
        }
        Node* temp2 = head;
        while(temp2 != nullptr) {
            newNode->random = u[temp2->random];
            temp2 = temp2->next;
            newNode = newNode->next;
        }
        return u[head];
    }
};
// @lc code=end

