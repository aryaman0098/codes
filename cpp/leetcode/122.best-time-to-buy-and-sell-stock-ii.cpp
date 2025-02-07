/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - prices[i - 1]) ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};
// @lc code=end

