/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> startTimes(n);
        unordered_map<int, int> u;
        for(int i = 0; i < n; i++) {
            u[intervals[i][0]] = i;
            startTimes[i] = intervals[i][0];
        } 
        sort(startTimes.begin(), startTimes.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(startTimes.begin(), startTimes.end(), intervals[i][1]);
            if (it == startTimes.end()) ans[i] = -1;
            else ans[i] = u[*it];
        }
        return ans;
    }
};
// @lc code=end

