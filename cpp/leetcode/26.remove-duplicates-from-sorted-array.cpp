/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int curr = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) continue;
            else {
                nums[curr] = nums[i];
                curr++;
            }
        }
        if(nums[nums.size() - 1] == nums[nums.size() - 1]) {
            nums[curr] = nums[nums.size() - 1];
        }
        return curr + 1;   
    }
};
// @lc code=end

