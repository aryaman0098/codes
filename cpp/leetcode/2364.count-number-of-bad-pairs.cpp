/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> u;
        long long goodPairs = 0;
        for(int i = 0; i < n; i++) {
            if(u.find(nums[i] - i) != u.end()) {
                goodPairs += u[nums[i] - i];
                u[nums[i] - i] += 1;
            } else {
                u[nums[i] - i] = 1;
            }
        }
        long long totalPairs = 0;
        for(int i = n - 1; i > 0; i--) totalPairs += i;
        return totalPairs - goodPairs;
    }
};
// @lc code=end

