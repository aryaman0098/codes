/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) { 
        if(nums.size() == 1 || nums[0] < nums[nums.size() - 1]) return nums[0];
        int l = 0, r = nums.size() - 1;
        while(l<=r) {
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if(nums[mid] < nums[mid - 1]) return nums[mid];
            else if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return -1;
    }
};
// @lc code=end
