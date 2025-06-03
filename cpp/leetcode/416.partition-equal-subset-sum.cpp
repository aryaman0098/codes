/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool dp(int i, int sum, vector<int>& nums, vector<vector<int>> &mem) {
        if(sum == 0) return true;
        if(sum < 0 || i == nums.size()) return false;
        if(mem[i][sum] != -1) return mem[i][sum];
        mem[i][sum] = dp(i + 1, sum - nums[i], nums, mem) || dp(i + 1, sum, nums, mem);
        return mem[i][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto c: nums) sum += c;
        if(sum % 2 != 0) return false;
        vector<vector<int>> mem(nums.size(), vector<int>(sum / 2 + 1, -1));
        return dp(0, sum / 2, nums, mem);
    }
};
// @lc code=end

