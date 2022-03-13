//https://practice.geeksforgeeks.org/problems/special-matrix4201/1

#include<bits/stdc++.h>

#define M 1000000009

using namespace std;

int FindWays(int n, int m, vector<vector<int>>blocked_cells){
    int dp[n + 1][m + 1];
    map<pair<int, int>, bool> mp;
    for(auto x : blocked_cells)
        mp[{ x[0] - 1, x[1] - 1 }] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[{ i, j }])
                dp[i][j] = 0;
            else{
                if(i == 0)
                    dp[i][j] = 1;
                else if(j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            }
        }
    }
    return dp[n - 1][m- 1];
}

int main(){

    return 0;
}
