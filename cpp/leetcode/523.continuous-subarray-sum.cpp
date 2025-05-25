/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        unordered_map<int, int> u;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum % k == 0 && i >= 1) return true;
            if(u.find(sum % k) != u.end()) {
                int index = u[sum % k];
                if(i - index >= 2) return true;
            } else {
                u[sum % k] = i;
            }
        } 
        return false;
    }
};
// @lc code=end

