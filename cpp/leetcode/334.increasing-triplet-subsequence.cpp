/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX, secondNum = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(firstNum >= nums[i]) {
                firstNum = nums[i];
            } else if(secondNum >= nums[i]) {
                secondNum = nums[i];
            } else {
                return true;
            }
        }
        return false; 
    }
};
// @lc code=end

