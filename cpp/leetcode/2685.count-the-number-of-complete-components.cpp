/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjL;
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (auto c : edges) {
            adjL[c[0]].push_back(c[1]);
            adjL[c[1]].push_back(c[0]);
        }
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            queue<int> q;
            vector<int> components;
            q.push(i);
            int count = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                if (visited[node])
                    continue;
                visited[node] = true;
                components.push_back(node);
                for (auto c : adjL[node])
                    q.push(c);
            }
            bool isComplete = true;
            for (auto node : components) {
                if (adjL[node].size() != components.size() - 1) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete)
                completeComponents++;
        }
        return completeComponents;
    }
};
// @lc code=end

