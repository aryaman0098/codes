/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void backtrack(
        vector<vector<int>> &ans, 
        vector<int> v, 
        vector<int> nums,
        unordered_map<int, int> u
    ) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for(auto c:  u) {
            if(c.second == 0) continue;
            v.push_back(c.first);
            u[c.first]--;
            backtrack(ans, v, nums, u);
            v.pop_back();
            u[c.first]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> u;
        for(auto c: nums) {
            if(u.find(c) == u.end()) u[c] = 0;
            u[c]++;
        }
        vector<vector<int>> ans;
        backtrack(ans, {}, nums, u);
        return ans;
    }
};
// @lc code=end

