/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> v(n, vector<int>(m, -1));
        function<int(int, int)> dp = [&](int index1, int index2) {
            if (index1 < 0)
                return index2 + 1;
            if (index2 < 0)
                return index1 + 1;
            if (v[index1][index2] != -1)
                return v[index1][index2];
            if (word1[index1] == word2[index2])
                return dp(index1 - 1, index2 - 1);
            int ans = 1 + min(dp(index1 - 1, index2),        // delete
                              min(dp(index1, index2 - 1),    // insert
                                  dp(index1 - 1, index2 - 1) // replace
                                  ));
            v[index1][index2] = ans;
            return v[index1][index2];
        };
        return dp(n - 1, m - 1);
    }
};
// @lc code=end

