/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */


// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> aM(n);
        for (auto& edge : edges) {
            aM[edge[0]].push_back(edge[1]);
            aM[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        stack<pair<int, int>> s;
        s.push({0, -1});
        int visitedCount = 0;
        while (!s.empty()) {
            auto [currNode, parent] = s.top();
            s.pop();
            if (visited[currNode]) return false;
            visited[currNode] = true;
            visitedCount++;
            for (int neighbor : aM[currNode]) {
                if (neighbor == parent) continue;
                s.push({neighbor, currNode});
            }
        }
        return visitedCount == n;
    }
};
// @lc code=end

