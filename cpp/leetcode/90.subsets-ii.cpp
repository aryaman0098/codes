/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;

        function<void(int)> backtrack = [&](int start) {
            ans.push_back(current);
            for (int i = start; i < nums.size(); ++i) {
                if (i > start && nums[i] == nums[i - 1])
                    continue;
                current.push_back(nums[i]);
                backtrack(i + 1);
                current.pop_back();
            }
        };
        backtrack(0);
        return ans;
    }
};
// @lc code=end

