/*
 * @lc app=leetcode id=3355 lang=cpp
 *
 * [3355] Zero Array Transformation I
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> d(nums.size());
        d[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            d[i] = nums[i] - nums[i - 1];
        }
        for (auto c : queries) {
            int l = c[0];
            int r = c[1];
            d[l] += -1;
            if ((r + 1) < nums.size()) {
                d[r + 1] -= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                nums[i] = d[i];
            }else {
                nums[i] = nums[i - 1] + d[i];
            }
            if (nums[i] > 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

