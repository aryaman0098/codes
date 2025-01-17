/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<int, int> memo;

    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        } else if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        } else {
            if(memo.find(nums.size()) != memo.end()) {
                return memo[nums.size()];
            }
            vector<int> v1 = vector<int>(nums.begin(), nums.end() - 1);
            vector<int> v2 = vector<int>(nums.begin(), nums.end() - 2);
            int ans =  max(rob(v1), rob(v2) + nums[nums.size() - 1]);
            memo[nums.size()] = ans;
            return ans;
        }
    }
};
// @lc code=end

