//https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>

using namespace std;

//     int u[201][201];

//     int dp(int i, int j, int m, int n, vector<vector<int>> grid){
//         if(i == 0 && j == 0){
//             return grid[i][j];
//         }else{
//             if(u[i][j] == -1){
//                 if(i == 0) 
//                     u[i][j] = grid[i][j] + dp(i, j - 1, m, n, grid);
//                 else if(j == 0) 
//                     u[i][j] = grid[i][j] + dp(i - 1, j, m, n, grid);
//                 else if(i > 0 && j > 0)  
//                         u[i][j] = grid[i][j] + min(dp(i - 1, j, m, n, grid), dp(i, j - 1, m, n, grid));
//             }
//             return u[i][j];
//         }
//     }

int minPathSum(vector<vector<int>>& grid) {
    int u[201][201];
    int m = grid.size();
    int n = grid[0].size();
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         u[i][j] = -1;
    //     }
    // }
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(i == m - 1 && j == n - 1)
                u[i][j] = grid[i][j];
            else if(i == m - 1)
                u[i][j] = grid[i][j] + u[i][j + 1];
            else if(j == n -1)
                u[i][j] = grid[i][j] + u[i + 1][j];
            else
                u[i][j] = grid[i][j] + min(u[i + 1][j], u[i][j + 1]);
        }
    }
    return u[0][0];
}

int main(){

    return 0;
}
