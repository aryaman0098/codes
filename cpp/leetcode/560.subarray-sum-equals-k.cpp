/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        int sum = 0, count = 0;
        u[0]++;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(u.find(sum) != u.end()) sum += u[sum];
            u[sum]++;
        }
    }
};
// @lc code=end

