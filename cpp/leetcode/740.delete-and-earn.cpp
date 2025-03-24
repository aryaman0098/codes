/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            unordered_map<int, int> gains;
            int maxNum = INT_MIN;
            for(auto c: nums) {
                if(gains.find(c) == gains.end()) gains[c] = 0;
                gains[c] += c;
                maxNum = max(maxNum, c);
            }
            vector<int> dp(maxNum + 1, 0);
            dp[0] = 0;
            dp[1] = (gains.find(1) == gains.end()) ? 0: gains[1];
            int ans = dp[1];
            for(int i = 2; i <= maxNum; i++) {
                int gain = (gains.find(i) == gains.end()) ? 0 : gains[i];
                dp[i] = max(dp[i - 1], gains[i] + dp[i - 2]);
                ans = max(ans, dp[i]);
            }
            return ans;
        }
    };
// @lc code=end

