/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = INT_MIN;
        while(l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if(height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end

      