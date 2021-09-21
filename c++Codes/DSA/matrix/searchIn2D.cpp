//https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target){
    int c = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    while(c < m && matrix[c][n - 1] < target){
        c++;
    }
    if(c == m){
        return false;
    }
    return binary_search(matrix[c].begin(), matrix[c].end(), target);
}

int main(){

    return 0;
}
