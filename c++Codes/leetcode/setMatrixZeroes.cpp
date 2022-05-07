//https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    map<pair<int, int>, bool> u;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0)
                u[{ i, j }] = true;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){    
            if(u[ {i, j} ]){
                for(int k = 0; k < m; k++)
                    matrix[k][j] = 0;
                for(int k = 0; k < n; k++)
                    matrix[i][k] = 0;
            }
        }
    }
}

int main(){

    return 0;
}
