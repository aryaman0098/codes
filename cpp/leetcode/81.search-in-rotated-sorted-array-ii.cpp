/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (r + l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
                continue;
            }
            else if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return - 1;
    }
};
// @lc code=end

