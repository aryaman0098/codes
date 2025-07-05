/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0], n = target.size();
        for (int i = 1; i < n; i++) {
            if (target[i] > target[i - 1])
                ans += target[i] - target[i - 1];
        }
        return ans;
    }
};
// @lc code=end

