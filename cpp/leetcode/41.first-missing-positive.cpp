/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) if(nums[i] < 0) nums[i] = 0;
        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if(0 <= index && index < n) {
                if(nums[index] == 0) nums[index] = -1 * (n + 10);
                else if(nums[index] > 0) nums[index] = -1 * nums[index];
            }
        }   
        for(int i = 1; i <= n; i++) {
            if(nums[i - 1] >= 0) return i;
        }
        return n + 1;
    }
};
// @lc code=end

