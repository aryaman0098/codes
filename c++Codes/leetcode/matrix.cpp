//https://leetcode.com/problems/01-matrix/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> d;
    queue<vector<int>> q;
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                d[i][j] = 0;
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                q.push(temp);
            }
        }
    }
    while(!q.empty()){
        vector<int> temp = q.front();
        q.pop();
        int i = temp[0], j = temp[1];
        if(i > 0 && mat[i - 1][j] == -1){
            d[i - 1][j] = d[i][j] + 1;
        }
        if(j > 0 && mat[i][j - 1] == -1){
            d[i][j - 1] = d[i][j - 1] + 1;
        }
        if(i < m - 1 && mat[i + 1][j] == -1){
            d[i + 1][j] = d[i][j] + 1;
        }
        if(j < n - 1 && mat[i][j + 1] == -1){
            d[i][j + 1] = d[i][j] + 1;
        }
    }
    return d;
}

int main(){

    return 0;
}
