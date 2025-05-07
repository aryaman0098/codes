/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, n = nums.size(), maxFreq = INT_MIN;
        long total = 0;
        for(int r = 0; r < n; r++) {
            long target = nums[r];
            total += nums[r];
            while(target * (r - l + 1) - total > k) {
                total -= nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
    }
};
// @lc code=end

