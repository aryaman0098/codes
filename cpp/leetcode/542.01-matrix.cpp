/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> distances(rows,  vector<int>(cols, 0));
        queue<vector<int>> q;
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {+1 ,0}, {0, +1}};
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                } 
            }
        }
        while(!q.empty()) {
            vector<int> node = q.front();
            q.pop();
            int row = node[0], col = node[1], distance = node[2];
            distances[row][col] = distance;
            for(auto d: directions) {
                int nrow = row + d.first, ncol = col + d.second;
                if(
                    nrow < rows &&
                    nrow >= 0 &&
                    ncol < cols &&
                    ncol >= 0 &&
                    !visited[nrow][ncol]
                ) {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol, distance + 1});
                }  
            }
        }
        return distances;   
    }
};
// @lc code=end

