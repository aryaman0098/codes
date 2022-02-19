//https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>

using namespace std;

int u[101][101];

int dp(int currM, int currN, int m, int n){
    if(currM == m - 1 && currN == n - 1){
        return 0;
    }else if(m - currM - 1 == 1 && currN == n - 1){
        return 1;
    }else if(n - currN - 1 == 1 && m - 1 == currM){
        return 1;
    }else{
        if(u[currM][currN] == -1){
            u[currM][currN] = dp(currM + 1, currN, m, n) + 
                                dp(currM, currN + 1, m, n);
        }
        return u[currM][currN];
    }
}

int uniquePaths(int m, int n) {
    if(m == 1 && n == 1){
        return 1;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            u[i][j] = -1;
        }
    }
    return dp(0, 0, m, n);        
}

int main(){

    return 0;
}
