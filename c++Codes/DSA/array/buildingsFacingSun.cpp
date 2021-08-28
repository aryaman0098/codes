//www.geeksforgeeks.org/number-buildings-facing-sumcd

#include<bits/stdc++.h>

using namespace std;

int facingSun(int arr[], int n){
    int currMax = arr[0];
    int count = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] >= currMax){
            count++;
            currMax = arr[i];
        }
    }
    return count;
}

int main(){
    int arr[] = {7,4,8,2,9};
    cout<<facingSun(arr, 5);
    return 0;
}
