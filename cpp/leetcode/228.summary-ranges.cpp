/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            int s = i, e = i;
            while(e + 1 < n && nums[e + 1] == nums[e] + 1) e++;
            if(s != e) {
                ans.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));
            } else if(s == e) {
                ans.push_back(to_string(nums[s]));
            }
            i = e;
        }
        return ans;
    }
};
// @lc code=end

