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
    pair<int, int> value;
    Node* next; 
    Node* prev;
    Node(pair<int, int> value) {
      this->value = value;
      next = nullptr;
      prev = nullptr;
    }
};

class LRUCache {
  private: 
    int cacheCapacity;
    unordered_map<int, Node*> u;
    Node* head;
    Node* tail;
  public:

    LRUCache(int size) {
      cacheCapacity = size;
      u = {};
      head = new Node({-1, -1});
      tail = new Node({-1, -1});
      head->next = tail;
      tail->prev = head;
    }

    void insertValueAtHead(int key, int value) {
      if(head->value.first == -1) {
        head->value = {key, value};
        return;
      }
      Node* newNode = new Node({key, value});
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    void deleteNode(Node* node) {
      if(node == head) {
        node->value = {-1, -1};
        return;
      }
      node->prev->next = node->next;
      node->next->prev = node->prev;
      delete node;
    }

    int get(int key) {
      if(u.find(key) == u.end()) {
        return -1;
      }
      int value = u[key]->value.second;
      deleteNode(u[key]);
      u.erase(key);
      insertValueAtHead(key, value);
      u[key] = head;
      return value;
    }
    
    void put(int key, int value) {
      if(u.find(key) != u.end()) {
        deleteNode(u[key]);
        u.erase(key);
        insertValueAtHead(key, value);
        u[key] = head;   
        return; 
      }
      if(u.size() < cacheCapacity) {
        insertValueAtHead(key, value);
        u[key] = head;
        return;
      }
      u.erase(tail->prev->value.first);
      deleteNode(tail->prev);
      insertValueAtHead(key, value);
      u[key] = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
