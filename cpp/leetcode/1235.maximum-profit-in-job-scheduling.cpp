/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        } 
        sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        for(int i = 0; i < n; i++) {
            endTime[i] = jobs[i][1];
        }
        vector<int> dp(n, 0);
        dp[0] = jobs[0][2];
        for(int i = 1; i < n; i++) {
            int prevIndex = upper_bound(endTime.begin(), endTime.begin() + i, jobs[i][0]) - endTime.begin() - 1;
            int currProfit = jobs[i][2];
            if (prevIndex >= 0) {
                currProfit += dp[prevIndex];
            }
            dp[i] = max(dp[i - 1], currProfit);
        }
        return dp[n - 1];
    }
};
// @lc code=end

