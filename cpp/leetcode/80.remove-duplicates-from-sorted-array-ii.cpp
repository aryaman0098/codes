/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int curr = 0;
        int r = 0;
        for(int i = 0; i < nums.size(); i++) {
            r = i;
            while(r < nums.size() && nums[r] == nums[i]) {
                r++;
            }
            if(r - 1 == i) {
                nums[curr] = nums[i];
                curr++;
            } else {
                nums[curr] = nums[i];
                curr++;
                nums[curr] = nums[i];
                curr++;
            }
            i = r - 1;
        }
        return curr;
    }
};
// @lc code=end

