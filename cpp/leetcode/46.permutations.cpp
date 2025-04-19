/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void backtrack(vector<vector<int>> &ans, vector<int> v, int pos, vector<int> nums) {
        if(pos == nums.size()) {
            ans.push_back(v);
            return;
        }
        for(auto c: nums) {
            if(find(v.begin(), v.end(), c) == v.end()) {
                v.push_back(c);
                backtrack(ans, v, pos + 1, nums);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, {}, 0, nums);
        return ans;
    }
};
// @lc code=end

