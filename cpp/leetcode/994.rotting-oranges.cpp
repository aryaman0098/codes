/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        int maxTime = 0;
        while(!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            int time = v[2], row = v[0], col = v[1];
            maxTime = max(maxTime, time);
            if(row > 0 && grid[row - 1][col] == 1) {
                q.push({row - 1, col, time + 1});
                grid[row - 1][col] = 2;
            }
            if(row < rows - 1 && grid[row + 1][col] == 1) {
                q.push({row + 1, col, time + 1});
                grid[row + 1][col] = 2;
            }
            if(col > 0 && grid[row][col - 1] == 1) {
                q.push({row, col - 1, time + 1});
                grid[row][col - 1] = 2;
            }
            if(col < cols - 1 && grid[row][col + 1] == 1) {
                q.push({row, col + 1, time + 1});
                grid[row][col + 1] = 2;
            }
        }

        for(auto c: grid) {
            for(auto d: c) {
                if(d == 1)  return -1;
            }
        }
        return maxTime;
    }
};
// @lc code=end

