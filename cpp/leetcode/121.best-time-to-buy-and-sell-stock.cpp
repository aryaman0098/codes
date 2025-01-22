/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPriceAfter = INT_MIN;
        int ans = INT_MIN;
        for(int i = prices.size() - 1; i >=0; i--) {
            if(prices[i] > maxPriceAfter) {
                maxPriceAfter = prices[i];
            }
            ans = max(ans, maxPriceAfter - prices[i]);
        }
        return ans;
    }
};
// @lc code=end

