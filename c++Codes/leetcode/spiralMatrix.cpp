//https://leetcode.com/problems/spiral-matrix/

#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int u = 0, d = m - 1, l = 0, r = n - 1;
    vector<int> ans;
    while(l <= r && u <= d){
        for(int i = l; i <= r; i++)
            ans.push_back(matrix[u][i]);
        u++;
        for(int i = u; i <= d; i++)
            ans.push_back(matrix[i][r]);
        r--;
        if(u <= d){
            for(int i = r; i >= l; i--)
                ans.push_back(matrix[d][i]);
                
        }
        d--;
        if(l <= r){
            for(int i = d; i >= u; i--)
                ans.push_back(matrix[i][l]);
            
        }
        l++;
    }
    return ans;
}

int main(){

    return 0;
}
