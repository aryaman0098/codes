/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> ans(n + 1);
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(i % 2 == 0) {
                ans[i] = ans[i / 2];
            } else {
                ans[i] = ans[i / 2] + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

