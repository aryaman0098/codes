/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start


class Node {
public:
    Node* prev;
    Node* next;
    int key;
    int val;

    Node(int key, int val) {
        this->next = nullptr;
        this->prev = nullptr;
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> u;
    Node* head;
    Node* tail;
    int capacity;

    Node* insertAfterHead(int key, int val) {
        Node* newNode = new Node(key, val);
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
        return newNode;
    }

    void deleteNode(Node* node) {
        int key = node->key;
        u.erase(key);
        Node* temp = node->prev;
        node->prev->next = node->next;
        node->next->prev = temp;
        delete(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail =  new Node(-1, - 1);
        tail->prev = head;
        head->next = tail;
    }
    
    int get(int key) {
        if(u.find(key) == u.end()) return -1;
        Node* node = u[key];
        int val = node->val;
        deleteNode(node);
        u[key] = insertAfterHead(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(u.size() >= capacity) {
            deleteNode(tail->prev);
        }
        u[key] = insertAfterHead(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
