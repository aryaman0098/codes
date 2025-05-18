/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int count = 0;
            while(!s.empty() && temperatures[i] >= s.top().first) {
                count += s.top().second;
                s.pop();
            } 
            if(s.empty()) {
                ans[i] = 0;
                s.push({temperatures[i], 0});
            } else {
                ans[i] = count + 1;
                s.push({temperatures[i], count + 1});
            }
        }
        return ans;
    }
};
// @lc code=end

