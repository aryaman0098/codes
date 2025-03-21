/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);
        int i = 0;
        dp[0] = 0;
        for(int day = 1; day <= lastDay; day++) {
            if(day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({
                    costs[0] + dp[day - 1],
                    costs[1] + dp[max(day - 7, 0)],
                    costs[2] + dp[max(day - 30, 0)]
                });
            }
        }
        return dp[lastDay];
    }
};
// @lc code=end

