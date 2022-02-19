//https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.size() == 0) 
        return triangle[0][0];
    int u[201][201];
    for(int i = triangle.size() - 1; i >= 0; i--){
        for(int j = triangle[i].size() - 1; j >= 0; j--){
            if(i == triangle.size() - 1)
                u[i][j] = triangle[i][j];
            else
                u[i][j] = triangle[i][j] + min(u[i + 1][j], u[i + 1][j + 1]);
        }
    }
    return u[0][0];
}


int main(){

    return 0;
}
