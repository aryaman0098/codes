/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 & n == 1) {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n- 1];
    }
};
// @lc code=end

