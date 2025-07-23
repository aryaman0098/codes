/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList;
        for (auto& c : dislikes) {
            adjList[c[0]].push_back(c[1]);
            adjList[c[1]].push_back(c[0]);
        }
        unordered_map<int, int> colour;
        for (int i = 1; i <= n; i++) {
            if (colour[i] != 0)
                continue;
            queue<pair<int, int>> q;
            q.push({i, 1});
            while (!q.empty()) {
                auto [node, c] = q.front();
                q.pop();

                if (colour[node] == 0) {
                    colour[node] = c;
                } else if (colour[node] != c) {
                    return false;
                }
                for (auto neighbor : adjList[node]) {
                    if (colour[neighbor] == 0) {
                        q.push({neighbor, 3 - c}); 
                    } else if (colour[neighbor] == c) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

