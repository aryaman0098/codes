/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    void visitIsland(vector<vector<char>>& grid, int r, int l) {
        if(grid[r][l] == '0') return;
        grid[r][l] = '0';
        if(r - 1 >= 0 && grid[r - 1][l] == '1') visitIsland(grid, r - 1, l);
        if(r + 1 < grid.size() && grid[r + 1][l] == '1') visitIsland(grid, r + 1, l);
        if(l - 1 >= 0 && grid[r][l - 1] == '1') visitIsland(grid, r, l - 1);
        if(l + 1 < grid[0].size() && grid[r][l + 1] == '1') visitIsland(grid, r, l + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    visitIsland(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

