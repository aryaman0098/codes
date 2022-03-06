//https://practice.geeksforgeeks.org/problems/85781966a9db2a1ac17eaaed26a947eba5740d56/1

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
    int m = after.size();
    int n = after[0].size();
    for(int i = m - 1; i > 0; i--){
        for(int j = n - 1; j > 0; j--){
            after[i][j] = after[i][j] - after[i - 1][j] - after[i - 1][j - 1] + after[i - 1][j - 1];
        }
    }
    for(int i = m - 1; i > 0; i--){
        after[i][0] = after[i - 1][0];
    }
    for(int j = n - 1; j > 0; j--){
        after[0][j] = after[0][j - 1];
    }
    return after;
}

int main(){

    return 0;
}
