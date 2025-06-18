/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int r = boxGrid.size(), c = boxGrid[0].size();
        vector<vector<char>> v(c, vector<char>(r, ' '));
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                v[j][r - 1 - i] = boxGrid[i][j];
            }
        }
        for (int j = 0; j < r; j++) {
            int lowestEmptyCell = c - 1;
            for (int i = c - 1; i >= 0; i--) {
                if (v[i][j] == '#') {
                    v[i][j] = '.';
                    v[lowestEmptyCell][j] = '#';
                    lowestEmptyCell--;
                }
                if (v[i][j] == '*') {
                    lowestEmptyCell = i - 1;
                }
            }
        }
        return v;
    }
};
// @lc code=end

