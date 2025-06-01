/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
    vector<string> strs;

    int dp(int m, int n, int i, vector<vector<vector<int>>> &c) {
        if(i == strs.size()) return 0;
        if(c[m][n][i] != -1) return c[m][n][i];
        int numOnes = 0, numZeroes = 0;
        for(auto ch: strs[i]) {
            numOnes += (ch == '1') ? 1: 0;
            numZeroes += (ch == '0') ? 1: 0; 
        }
        int take = -1, notTake;
        if(m >= numZeroes && n >= numOnes) take = 1 + dp(m - numZeroes, n - numOnes, i + 1, c);
        notTake = dp(m, n, i + 1, c);
        c[m][n][i] = max(take, notTake);
        return c[m][n][i];
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> c(vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(s, -1))));
        this->strs = strs;
        int ans = dp(m, n, 0, c);
        return ans;
    }
};
// @lc code=end

