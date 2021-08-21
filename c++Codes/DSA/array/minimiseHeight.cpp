#include<bits/stdc++.h>

using namespace std;

int minimisematrix(int arr[], int n, int k){
    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return max - min - 2*k;
}

int main(){
    int arr[] = {1,5,8,10};
    cout<<minimisematrix(arr, 4, 2);
}