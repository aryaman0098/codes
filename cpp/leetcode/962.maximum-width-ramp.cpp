/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> minTillNow;
        int n = nums.size();
        int min = INT_MAX;
        int currMinIndex = 0;
        for(int i = 0; i < n; i++) {
            if(min > nums[i]) {
                min = nums[i];
            }
            minTillNow.push_back(min);
        }
        int r = n - 1, l = n - 1;
        int ans = INT_MIN;
        while(l <= r && l >= 0 && r >= 0) {
            if(minTillNow[l] <= nums[r]) {
                ans = max(ans, r - l);
                l--;
            } else {
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

