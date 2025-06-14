/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_set<int> minesSet;
        for (auto c : mines)
            minesSet.insert(c[0] * n + c[1]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count = (minesSet.find(i * n + j) == minesSet.end())
                             ? count + 1
                             : 0;
                dp[i][j] = count;
            }
            count = 0;
            for (int j = n - 1; j >= 0; j--) {
                count = (minesSet.find(i * n + j) == minesSet.end())
                             ? count + 1
                             : 0;
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                count = (minesSet.find(i * n + j) == minesSet.end())
                             ? count + 1
                             : 0;
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            for (int i = n - 1; i >= 0; i--) {
                count = (minesSet.find(i * n + j) == minesSet.end())
                             ? count + 1
                             : 0;
                dp[i][j] = min(dp[i][j], count);
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};
// @lc code=end

