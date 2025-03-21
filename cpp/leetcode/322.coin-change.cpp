/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i >= coins[j]) {
                    int prev = dp[i - coins[j]];
                    if(prev != -1) {
                        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                    }
                }
            }
            dp[i] = (dp[i] == INT_MAX) ? -1 : dp[i];
        }
        return dp[amount];
    }
};
// @lc code=end

