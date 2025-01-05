/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax, rightMax;
        int maxHeight = INT_MIN;
        for(int i = 0; i < height.size(); i++) {
            maxHeight = max(maxHeight, height[i]);
            leftMax.push_back(maxHeight);
        }
        maxHeight = INT_MIN;
        for(int i = height.size() - 1; i >= 0; i--) {
            maxHeight = max(maxHeight, height[i]);
            rightMax.insert(rightMax.begin(), maxHeight);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            int limitingHeiht = min(leftMax[i], rightMax[i]);
            if(limitingHeiht > height[i]) ans += limitingHeiht - height[i];
        }
        return ans;
    }
};
// @lc code=end

