/*
 * @lc app=leetcode id=2202 lang=cpp
 *
 * [2202] Maximize the Topmost Element After K Moves
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if( k % 2 != 0 && nums.size() == 1) return -1;
        if(k == 0 || k == 1) return nums[k];
        int n = (k > nums.size()) ? nums.size() : k - 1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            ans = max(ans, nums[i]);
        }
        if(k < nums.size()) {
            ans = max(ans, nums[k]);
        }
        return ans;
    }
};
// @lc code=end

