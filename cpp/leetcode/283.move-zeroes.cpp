/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
void moveZeroes(vector<int>& nums) {
    int lastZeroAt = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            swap(nums[lastZeroAt], nums[i]);
            lastZeroAt++;
        }
    }
}
};
// @lc code=end

