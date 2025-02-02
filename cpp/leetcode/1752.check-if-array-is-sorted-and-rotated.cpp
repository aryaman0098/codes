/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int min = nums[0];
        bool rotationDetected = false;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(rotationDetected) { 
                if(!(nums[i] <= nums[i + 1] && nums[i] <= min)) {
                    return false;
                }
            } else {
                if(nums[i] > nums[i + 1]) {
                    rotationDetected = true;
                }
            }
        }
        if(rotationDetected && nums[nums.size() - 1] > min) return false;
        return true;
    }
};
// @lc code=end

