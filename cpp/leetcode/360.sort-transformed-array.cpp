/*
 * @lc app=leetcode id=360 lang=cpp
 *
 * [360] Sort Transformed Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        function<int(int)> transform = [&](int x) {
            return a * x * x + b * x + c;
        };
        int l = 0, r = nums.size() - 1;
        vector<int> ans;
        if (a >= 0) {
            while (l <= r) {
                int lT = transform(nums[l]);
                int rT = transform(nums[r]);
                if (lT < rT) {
                    ans.push_back(rT);
                    r--;
                } else {
                    ans.push_back(lT);
                    l++;
                }
            }
            reverse(ans.begin(), ans.end());
        } else {
            while (l <= r) {
                int lT = transform(nums[l]);
                int rT = transform(nums[r]);
                if (lT < rT) {
                    ans.push_back(lT);
                    l++;
                } else {
                    ans.push_back(rT);
                    r--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

