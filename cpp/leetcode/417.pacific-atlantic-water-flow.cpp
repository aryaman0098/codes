/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<bool>> bfs(vector<vector<int>> &heights, int intialRow, int initialCol) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> reachable(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < c; i++) {
            q.push({intialRow, i});
            reachable[intialRow][i] = true;
        }
        for(int i = 0; i < r; i++) {
            q.push({i, initialCol});
            reachable[i][initialCol] = true;
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) { 
            pair<int, int> n = q.front();
            q.pop();
            for(auto d: directions) {
                int nr = n.first + d.first, nc = n.second + d.second;
                if(nr >= 0 && nr < r && nc >= 0 && nc < c && heights[nr][nc] >= heights[n.first][n.second] && !reachable[nr][nc]) {
                    reachable[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return reachable;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> r1 = bfs(heights, 0, 0);
        vector<vector<bool>> r2 = bfs(heights, r - 1, c - 1);
        vector<vector<int>> ans;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(r1[i][j] && r2[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
// @lc code=end

