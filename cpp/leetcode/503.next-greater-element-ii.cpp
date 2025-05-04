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
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() < nums[i % n]) s.pop();
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

