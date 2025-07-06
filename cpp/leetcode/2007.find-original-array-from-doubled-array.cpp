/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0)
            return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> u;
        for (auto c : changed)
            u[c]++;
        vector<int> ans;
        for (auto c : changed) {
            if (u[c] == 0)
                continue;
            if (u[2 * c] == 0)
                return {};
            ans.push_back(c);
            u[c]--;
            u[2 * c]--;
        }
        return ans;
    }
};
// @lc code=end

