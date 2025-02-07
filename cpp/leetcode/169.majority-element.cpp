/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int candidate = nums[0], count = 0;
        for(auto c: nums) {
            if(c == candidate) {
                candidate = c;
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                candidate = c;
                count++;
            }
        }
        return candidate;
    }
};
// @lc code=end

