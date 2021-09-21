//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include<bits/stdc++.h>

using namespace std;

    
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c){
    int k = 0, m = r, l = 0, n = c;
    vector<int> ans;
    while(k < m && l < n){
        for(int i = l; i < n; i++){
            ans.push_back(matrix[k][i]);
        }
        k++;
        for(int i = k; i < m; i++){
            ans.push_back(matrix[i][n - 1]);
        }
        n--;
        if(k < m){
            for(int i = n - 1; i >= l; i--){
                ans.push_back(matrix[m - 1][i]);
            }
            m--;
        }
        if(l < n){
            for(int i = m - 1; i >= k; i--){
                ans.push_back(matrix[i][l]);
            }
            l--;
        }
    }
    return ans;
}

int main(){

}
