//https://leetcode.com/problems/unique-paths-ii/

#include<bits/stdc++.h>

using namespace std;

int u[101][101];

int dp(int currM, int currN, int m, int n, vector<vector<int>>& obstacleGrid){
    if(currM <= m - 1 && currN <= n - 1 && obstacleGrid[currM][currN] == 1){
        return 0;
    }if(currM == m - 1 && currN == n - 1){
        return 0;
    }else if(m - currM - 1 == 1 && currN == n - 1){
        return 1;
    }else if(n - currN - 1 == 1 && m - 1 == currM){
        return 1;
    }else{
        if(u[currM][currN] == -1){
            u[currM][currN] = dp(currM + 1, currN, m, n, obstacleGrid) + 
                                dp(currM, currN + 1, m, n, obstacleGrid);
        }
        return u[currM][currN];
    }
}


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m - 1][n -1 ] == 1){
        return 0;
    }else if(m == 1 && n == 1){
        return 1;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            u[i][j] = -1;
        }
    }
    return dp(0, 0, m, n, obstacleGrid);
}

int main(){

    return 0;
}
