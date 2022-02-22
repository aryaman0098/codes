//https://leetcode.com/problems/maximal-square/

#include<bits/stdc++.h>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n];
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == '1')
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }
    for(int i = 0; i < n; i++){
        if(matrix[0][i] == '1')
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    int x, y, z, a, b;
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == '0')
                dp[i][j] = 0;
            else{
                x = dp[i - 1][j];
                y = dp[i][j - 1];
                z = dp[i - 1][j - 1];
                a = min(x, y);
                b = min(z, a);
                dp[i][j] = b + 1;
            }
        }
    }
    
    int max = INT_MIN;
    for(int i = 0; i < m; i++){
        for(int j = 0; j <  n; j++){
            if(max < dp[i][j])
                max = dp[i][j];
        }
    }
    return max*max;
}

int main(){

    return 0;
}
