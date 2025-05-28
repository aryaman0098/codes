/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int currLength = 0, maxLength = 0, l = 0, r = 0, oneFreq = 0;
        while(r < nums.size()) {
            if(nums[r] == 1) oneFreq++;
            currLength = r - l + 1;
            if(currLength - oneFreq <= k) {
                maxLength = max(maxLength, currLength);
            } else {
                while(currLength - oneFreq > k) {
                    if(nums[l] == 1) oneFreq--;
                    l++;
                    currLength = r - l + 1;
                }
            }
            r++;
        }
        return maxLength;
    }
};
// @lc code=end

