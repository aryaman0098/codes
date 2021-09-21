//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include<bits/stdc++.h>

using namespace std;

int median(vector<vector<int>> &matrix, int r, int c){
    int min = INT_MAX, max = INT_MIN;
    int counter = 0;
    while(counter < r){
        if(min > matrix[counter][0]){
            min  = matrix[counter][0];
        }
        if(max < matrix[counter][c - 1]){
            max = matrix[counter][c - 1];
        }
        counter++;
    }
    int desired = (r * c + 1) / 2;
    int mid;
    while(min < max){
        mid = min + (max - min) / 2;
        int place = 0;
        for(int i = 0; i < r; i++){
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if(place < desired){
            min = mid + 1;
        }else{
            max = mid;
        }
    }
    return mid;
}

int main(){

    return 0;
}
