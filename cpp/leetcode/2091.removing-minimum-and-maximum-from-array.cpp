/*
 * @lc app=leetcode id=2091 lang=cpp
 *
 * [2091] Removing Minimum and Maximum From Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX, maxVal = INT_MIN;
        int minIdx = -1, maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        int front = max(minIdx + 1, maxIdx + 1);
        int back = max(n - minIdx, n - maxIdx);
        int mix1 = minIdx + 1 + (n - maxIdx);
        int mix2 = maxIdx + 1 + (n - minIdx);

        return min({front, back, mix1, mix2});
    }
};
// @lc code=end

