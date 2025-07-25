/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> c(n, vector<int>(m, -1));
        vector<vector<int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        function<int(int, int)> dfs = [&](int i, int j) {
            if (c[i][j] != -1)
                return c[i][j];
            int ans = 1;
            for (int k = 0; k < 4; k++) {
                int nr = i + d[k][0], nc = j + d[k][1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    matrix[nr][nc] > matrix[i][j]) {
                    ans = max(ans, 1 + dfs(nr, nc));
                }
            }
            c[i][j] = ans;
            return ans;
        };
        int maxPath = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxPath = max(maxPath, dfs(i, j));
            }
        }
        return maxPath;
    }
};
// @lc code=end

