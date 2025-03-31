/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
private:
    int robWithoutCirlce(vector<int> nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i <= nums.size() - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[dp.size() - 1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> c1 = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> c2 = vector<int>(nums.begin() + 1, nums.end());
        return max(robWithoutCirlce(c1), robWithoutCirlce(c2));
    }
};
// @lc code=end

