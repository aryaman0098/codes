/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size();
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        int l = 1, r = n - 2;
        int ans;
        while(l < r) {
            int mid = (r + l) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                ans = mid;
                break;
            }
            else if(nums[mid] > nums[mid + 1]) r = mid - 1;
            else l = mid + 1;
        }  
        return ans;
    }
};
// @lc code=end

