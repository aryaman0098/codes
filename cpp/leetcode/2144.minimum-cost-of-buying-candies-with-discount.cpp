/*
 * @lc app=leetcode id=2144 lang=cpp
 *
 * [2144] Minimum Cost of Buying Candies With Discount
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0, n = cost.size(), numBought = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (numBought == 2) {
                numBought = 0;
                continue;
            } else {
                ans += cost[i];
                numBought++;
            }
        }
        return ans;
    }
};
// @lc code=end

