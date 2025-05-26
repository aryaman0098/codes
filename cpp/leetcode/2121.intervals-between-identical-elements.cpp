/*
 * @lc app=leetcode id=2121 lang=cpp
 *
 * [2121] Intervals Between Identical Elements
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> u;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(u.find(arr[i]) == u.end()) u[arr[i]] = {};
            u[arr[i]].push_back(i);
        }
        vector<long long> ans(n);
        for(auto [val, indices]: u) {
            int m = indices.size();
            vector<long long> ps(m);
            ps[0] = indices[0];
            for(int i = 1; i < m; i++) ps[i] = indices[i] + ps[i - 1];
            for(int i = 0; i < m; i++) {
                long long left = (long long)i * indices[i] - (i > 0 ? ps[i - 1] : 0);
                long long right = (ps[m - 1] - ps[i]) - (long long)(m - i - 1) * indices[i];
                ans[indices[i]] = right + left;
            }
        }
        return ans;
    }
};
// @lc code=end

