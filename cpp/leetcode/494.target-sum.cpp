/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> c(n + 1, vector<int>(2001, -1));
        function<int(int, int)> dp = [&](int index, int val) {
            if (index == n) {
                if (val == target)
                    return 1;
                else
                    return 0;
            }
            if (c[index][1000 - val] != -1)
                return c[index][1000 - val];
            int substract = dp(index + 1, val - nums[index]);
            int add = dp(index + 1, val + nums[index]);
            c[index][1000 - val] = substract + add;
            return c[index][1000 - val];
        };
        return dp(0, 0);
    }
};
// @lc code=end

