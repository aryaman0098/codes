/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i - 1] < nums[i]) {
                int pivotIndex = i - 1;
                int swapElementIndex = i;
                int j;
                for(j = i; j < nums.size(); j++) {
                    if(nums[j] > nums[pivotIndex] && nums[j] < swapElementIndex) {
                        swapElementIndex = j;
                    }
                }
                int temp = nums[pivotIndex];
                nums[pivotIndex] = nums[swapElementIndex];
                nums[swapElementIndex] = temp;
                sort(nums.begin() + i, nums.end());
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

