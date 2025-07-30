/*
 * @lc app=leetcode id=2039 lang=cpp
 *
 * [2039] The Time When the Network Becomes Idle
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        unordered_map<int, vector<int>> adj;
        int n = patience.size();
        for (auto c : edges) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int> distance(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> nVal = q.front();
            q.pop();
            if (distance[nVal.first] != INT_MAX)
                continue;
            distance[nVal.first] = nVal.second;
            for (auto c : adj[nVal.first]) {
                q.push({c, nVal.second + 1});
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < n; i++) {
            int roundTrip = 2 * distance[i];
            if (roundTrip <= patience[i]) {
                ans = max(ans, roundTrip);
            } else {
                int lastSent = ((roundTrip - 1) / patience[i]) * patience[i];
                ans = max(ans, lastSent + roundTrip);
            }
        }
        return 1 + ans;
    }
};
// @lc code=end

