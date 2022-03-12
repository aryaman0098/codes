//https://practice.geeksforgeeks.org/problems/height-using-parent-array4103/1

#include<bits/stdc++.h>

using namespace std;

int findHeight(int N, int arr[]){
    arr[0] = 1;
    for(int i = 1; i < N; i++)
        arr[i] = arr[arr[i]] + 1;
    int max = INT_MIN;
    for(int i = 1; i < N; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

int main(){

    return 0;
}
