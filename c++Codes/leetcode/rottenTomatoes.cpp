//https://leetcode.com/problems/rotting-oranges/

#include<bits/stdc++.h>

using namespace std;

vector<int> dir = { 0, 1, 0, - 1, 0 };

bool isValid(int i, int j, int m, int n, vector<vector<int>> grid){
    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2 || grid[i][j] == 0)
        return false;
    return true;
}

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    vector<int> time;
    int max = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                q.emplace(i, j);
                time.push_back(0);
            }
        }
    }
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        int t = time[0];
        time.erase(time.begin());
        for(int k = 0; k < 4; k++){
            int ni = i + dir[k], nj = j + dir[k + 1];
            if(isValid(ni, nj, m, n, grid)){
                grid[ni][nj] = 2;
                q.emplace(ni, nj);
                time.push_back(t + 1);
                if(t + 1 > max) max = t + 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1)
                return -1;
        }
    }
    return max;
}

int main(){

    return 0;
}
