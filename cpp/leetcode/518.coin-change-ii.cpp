/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> c(amount + 1, vector<int>(n, -1));
        function<int(int, int)> dp = [&](int amount, int index) {
            if (amount < 0)
                return 0;
            if (amount == 0) 
                return 1;
            if (index == 0) {
                if (amount % coins[index] == 0)
                    return 1;
                else
                    return 0;
            }
            if (c[amount][index] != -1)
                return c[amount][index];
            int notTake = dp(amount, index - 1);
            int take = dp(amount - coins[index], index);
            c[amount][index] = notTake + take;
            return c[amount][index];
        };
        return dp(amount, n - 1);
    }
};
// @lc code=end

