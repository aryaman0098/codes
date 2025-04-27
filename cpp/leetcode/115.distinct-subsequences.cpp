/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        cout<<n<<" "<<m<<endl;
        if(n < m) return 0;
        if(n == m && s == t) return 1;
        if(n == m && s != t) return 0; 
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
// @lc code=end

