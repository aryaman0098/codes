/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currLength = 0, maxLength = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                int j = i;
                while(j < n && nums[j] == 1) {
                    currLength = j - i + 1;
                    j++;
                }
                maxLength = max(maxLength, currLength);
                i = j;
            }
            currLength = 0;
        }
        return maxLength;
    }
};
// @lc code=end

