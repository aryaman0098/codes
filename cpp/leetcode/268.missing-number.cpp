/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        int sumOfList = 0;
        for(auto c: nums) sumOfList += c;
        return sum - sumOfList;
    }
};
// @lc code=end

