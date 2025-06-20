/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        function<int(int, int, int)> explore = [&](int r, int c, int id) {
            if (r < 0 || c < 0 || r == row || c == col || grid[r][c] != 1)
                return 0;
            grid[r][c] = id;
            return 1 + explore(r - 1, c, id) + explore(r, c - 1, id) +
                   explore(r + 1, c, id) + explore(r, c + 1, id);
        };
        int id = 2;
        unordered_map<int, int> u;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    u[id] = explore(i, j, id);
                    ans = max(ans, u[id]);
                    id++;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    if (i > 0 && grid[i - 1][j] != 0)
                        s.insert(grid[i - 1][j]);
                    if (j > 0 && grid[i][j - 1] != 0)
                        s.insert(grid[i][j - 1]);
                    if (i < row - 1 && grid[i + 1][j] != 0)
                        s.insert(grid[i + 1][j]);
                    if (j < col - 1 && grid[i][j + 1] != 0)
                        s.insert(grid[i][j + 1]);
                    int sum = 0;
                    for (auto c : s)
                        sum += u[c];
                    ans = max(ans, sum + 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

