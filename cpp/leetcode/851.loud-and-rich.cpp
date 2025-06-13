/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> v(n);
        vector<int> ans(n, -1);
        for (auto c : richer)
            v[c[1]].push_back(c[0]);
        function<int(int)> dfs = [&](int node) {
            if (ans[node] == -1) {
                ans[node] = node;
                for (auto c : v[node]) {
                    int candidate = dfs(c);
                    if (quiet[candidate] < quiet[ans[node]])
                        ans[node] = candidate;
                }
            }
            return ans[node];
        };
        for (int i = 0; i < n; i++)
            dfs(i);
        return ans;
    }
};
// @lc code=end

