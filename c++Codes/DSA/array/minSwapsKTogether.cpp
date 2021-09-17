//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

#include<bits/stdc++.h>

using namespace std;

int minSwap(int *arr, int n, int k){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= k){
            cnt++;
        }
    }
    int Min = 0;
    for(int m = 0; m < cnt; m++){
        if(arr[m] > k){
            Min++;
        }
    }
    int ans = Min;
    for(int i = 0, j = cnt; j < n; i++, j++){
        if(arr[i] > k){
            Min--;
        }
        if(arr[j] > k){
            Min++;
        }
        ans = min(Min, ans);
    }
    return ans;
}

int main(){

    int arr[] = {8,9,6,1,2,3,7,8,1,2,3,4,6,7};
    minSwap(arr, 14, 6);
    return 0;
}
