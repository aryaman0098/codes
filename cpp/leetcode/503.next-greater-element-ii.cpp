/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(n);
        int n = nums.size();
        for(int i = 2 * n - 1; i >= 0; i--) {
            if(!s.empty() && s.top() < nums[i % n]) s.pop();
            if(i < n) {
                if(s.empty()) ans[i] = -1;
                else ans[i] = s.top();
            }
            s.push(nums[i % n]);
        }
        return ans;
    }
};
// @lc code=end

