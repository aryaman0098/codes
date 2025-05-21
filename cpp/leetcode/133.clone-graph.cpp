/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> u;
        queue<Node*> q;
        u[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor : curr->neighbors) {
                if (u.find(neighbor) == u.end()) {
                    u[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                u[curr]->neighbors.push_back(u[neighbor]);
            }
        }
        return u[node];
    }
};
// @lc code=end

