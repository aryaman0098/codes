/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> u;

public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (u.find(nums[i]) == u.end())
                u[nums[i]] = {};
            u[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);
        double randomNumber = dis(gen);
        int indicesLength = u[target].size();
        int index = 0 + (int)(indicesLength * randomNumber);
        return u[target][index];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

