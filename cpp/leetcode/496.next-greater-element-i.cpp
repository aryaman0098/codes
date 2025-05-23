/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums[i % n]) s.pop();
            if(i < n) {
                ans[i] = (s.empty()) ? -1 : s.top();
            }
            s.push(nums[i % n]);
        }
        return ans;
    }
};
// @lc code=end

