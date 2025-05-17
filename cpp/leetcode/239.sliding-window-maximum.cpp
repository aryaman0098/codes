/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(!q.empty() && q.front() == i - k) q.pop_front();
            while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1 ) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
// @lc code=end

