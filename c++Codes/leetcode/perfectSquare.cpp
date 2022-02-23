//https://leetcode.com/problems/perfect-squares/

#include<bits/stdc++.h>

using namespace std;

int numSquares(int n) {
    int dp[n + 1];
    dp[0] = 0;
    int Min;
    for(int i = 1; i <= n; i++){
        Min = INT_MAX;
        int j = 1;
        while(j*j <= i){
            Min = min(Min, dp[i - j*j] + 1);
            j++;
        }
        dp[i] = Min;
    }
    return dp[n];
}

int main(){

    return 0;
}
