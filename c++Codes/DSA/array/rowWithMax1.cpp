#include<bits/stdc++.h>

using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m){
    int row = -1;
    int col = m - 1;
    for(int j = 0; j < m; j++){
        if(arr[0][j] == 1){
            col = j;
            row = 0;
            break;
        }
    }
    for(int i  = 1; i < n; i++){
        if(arr[i][col] == 1){
            row = i;
            for(int j = col - 1; j >=0; j--){
                if(arr[row][j] == 0){
                    col = j;
                    break;
                }
            }
        }
    }
    return row;
}

int main(){

}
