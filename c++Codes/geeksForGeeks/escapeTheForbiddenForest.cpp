//https://practice.geeksforgeeks.org/problems/a4f19ea532cee502aabec77c07e0d0a45b76ecf9/1

#include<bits/stdc++.h>

using namespace std;

int build_bridges(string str1, string str2){
    int n1 = str1.length(), n2 = str2.length();
    int dp[n1 + 1][n2 + 1];
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}

int main(){

    return 0;
}
