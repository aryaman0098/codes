/*
 * @lc app=leetcode id=2008 lang=cpp
 *
 * [2008] Maximum Earnings From Taxi
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int l = rides.size();
        vector<long long> dp(l, 0);
        sort(rides.begin(), rides.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        vector<int> endTimes(l);
        for(int i = 0; i < l; i++) {
            endTimes[i] = rides[i][1];
        }
        dp[0] = rides[0][1] - rides[0][0] + rides[0][2];
        for(int i = 1; i < l; i++) {
            int prev = upper_bound(endTimes.begin(), endTimes.begin() + i, rides[i][0]) - endTimes.begin() - 1;
            long long currEarnings = rides[i][1] - rides[i][0] + rides[i][2];
            if(prev >= 0) {
                currEarnings += dp[prev];
            }
            dp[i] = max(dp[i - 1], currEarnings);
        }
        return dp[l - 1];
    }
};
// @lc code=end

