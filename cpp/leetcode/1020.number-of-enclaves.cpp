/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int x, int  y, int m,  int n, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == 0) return;
        visited[x][y] = true;
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(auto direction: directions) {
            int nx = x + direction.first, ny = y + direction.second;
            dfs(nx, ny, m, n, grid, visited);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) if(!visited[i][0]) dfs(i, 0, m, n, grid, visited);
        for(int i = 0; i < m; i++) if(!visited[i][n - 1]) dfs(i, n - 1, m, n, grid, visited);
        for(int i = 0; i < n; i++) if(!visited[0][i]) dfs(0, i, m, n, grid, visited);
        for(int i = 0; i < n; i++) if(!visited[m - 1][i]) dfs(m - 1, i, m, n, grid, visited);

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) count++;
            }
        }
        return count;
    }
};
// @lc code=end

