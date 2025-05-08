/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void getSubsets(vector<vector<int>> &ans, vector<int> container, vector<int> nums, int start) {
        ans.push_back(container);
        for(int i = start; i < nums.size(); i++) {
            container.push_back(nums[i]);
            getSubsets(ans, container, nums, i + 1);
            container.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        getSubsets(ans, {}, nums, 0);
        return ans;
    }
};
// @lc code=end

