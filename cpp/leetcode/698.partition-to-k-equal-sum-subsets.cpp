/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int target;
    bool backtrack(int pos, int sum, vector<int>& nums, vector<bool>& used,
                   int kLeft) {
        if (kLeft == 0)
            return true;
        if (sum == 0)
            return backtrack(0, target, nums, used, kLeft - 1);
        for (int i = pos; i < nums.size(); i++) {
            if (used[i] || sum - nums[i] < 0)
                continue;
            used[i] = true;
            if (backtrack(i + 1, sum - nums[i], nums, used, kLeft))
                return true;
            used[i] = false;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto c : nums)
            sum += c;
        if (sum % k != 0)
            return false;
        target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target)
            return false;
        vector<bool> used(nums.size(), false);
        return backtrack(0, target, nums, used, k);
    }
};
// @lc code=end

