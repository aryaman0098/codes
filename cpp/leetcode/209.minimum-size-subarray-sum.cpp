/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
    public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = INT_MAX;
        int l = 0, r = 0, n = nums.size() - 1;
        int sum = nums[r];
        while(r <= n && l <= r) {
            if(sum >= target) {
                if(l == r) {
                    return 1;
                }
                minSize = min(r - l + 1, minSize);
                sum -= nums[l];
                l++;
            } else {
                r++;
                if(r <= n) {
                    sum += nums[r];
                }
            }
        }
        return (minSize == INT_MAX) ? 0 : minSize;
    }
};
// @lc code=end

