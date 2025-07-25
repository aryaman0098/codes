/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> c(n, (vector<int>(2, -1)));
//         function<int(int, int)> dp = [&](int index, int buy) {
//             if (index == n)
//                 return 0;
//             if (c[index][buy] != -1)
//                 return c[index][buy];
//             int ans;
//             if (buy) {
//                 ans = max(-prices[index] + dp(index + 1, 0),
//                           dp(index + 1, 1));
//             } else {
//                 ans = max(-fee + prices[index] + dp(index + 1, 1),
//                           dp(index + 1, 0));
//             }
//             c[index][buy] = ans;
//             return c[index][buy];
//         };
//         return dp(0, 1);
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];        
        for (int i = 1; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i] - fee); 
            hold = max(hold, cash - prices[i]);       
        }
        return cash;
    }
};
// @lc code=end

