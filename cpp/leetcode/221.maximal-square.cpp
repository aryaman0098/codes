/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxVal = 0;
        vector<vector<int>> c(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
          c[i][0] = matrix[i][0] - '0';
          if(c[i][0] == 1) maxVal = 1; 
        }
        for (int i = 0; i < n; i++) {
          c[0][i] = matrix[0][i] - '0'; 
          if(c[0][i] == 1) maxVal = 1; 
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') {
                    c[i][j] = 0;
                } else {
                    if (c[i - 1][j - 1] != 0 && c[i - 1][j] != 0 &&
                        c[i][j - 1] != 0) {
                        c[i][j] = 1 + min(c[i - 1][j - 1], min(c[i - 1][j], c[i][j - 1]));
                    } else {
                        c[i][j] = 1;
                    }
                }
                maxVal = max(maxVal, c[i][j]);
            }
        }
        return maxVal * maxVal;
    }
};
// @lc code=end

