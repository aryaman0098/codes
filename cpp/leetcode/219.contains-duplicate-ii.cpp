/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(u.find(nums[i]) != u.end()) {
                if(i - u[nums[i]] <= k) return true;
                u[nums[i]] = i;
            } else {
                u[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end

