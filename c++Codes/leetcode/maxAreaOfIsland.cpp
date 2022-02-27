//https://leetcode.com/problems/max-area-of-island/

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> grid, int i, int j, vector<vector<bool>>& isVisited, int* currArea){
    *currArea += 1;
    isVisited[i][j] = true;
    if(i > 0 && grid[i - 1][j] == 1 && !isVisited[i - 1][j])
        dfs(grid, i - 1, j, isVisited, currArea);
    if(j > 0 && grid[i][j - 1] == 1 && !isVisited[i][j - 1])
        dfs(grid, i, j - 1, isVisited, currArea);
    if(i < grid.size() - 1 && grid[i + 1][j] == 1 && !isVisited[i + 1][j])
        dfs(grid, i + 1, j, isVisited, currArea);
    if(j < grid[0].size() - 1 && grid[i][j + 1] == 1 && !isVisited[i][j + 1])
        dfs(grid, i, j + 1, isVisited, currArea);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    vector<vector<bool>> isVisited;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
        vector<bool> temp;
        for(int j = 0; j < n; j++){
            temp.push_back(false);
        }
        isVisited.push_back(temp);
    }    
    int currArea = 0;
    int maxArea = INT_MIN;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1 && !isVisited[i][j]){
                currArea = 0;
                dfs(grid, i, j, isVisited, &currArea);
            }
            if(currArea > maxArea){
                maxArea = currArea;
            }
        }
    }
    return maxArea;
}

int main(){

    return 0;
}
