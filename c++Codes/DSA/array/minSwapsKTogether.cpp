//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

#include<bits/stdc++.h>

using namespace std;

int minSwap(int *arr, int n, int k){
    int i, j;
    vector<int> index(2);
    int max = INT_MIN;
    int flag = 1;
    for(int m = 0; m < n; m++){
        if(arr[m] < k){
            if(flag == 1){
                i = m;
                flag = 0;
            }
        }else{
            if(flag == 0){
                j = m - 1;
                if(max < j - i + 1){
                    index[0] = i;
                    index[1] = j;
                }
                flag = 1;
            }
        }
    }
    int num = 0;
    for(int m = 0; m < n; m++){
        if(m >= index[0] && m <= index[1]){
            continue;
        }
        if(arr[m] < k){
            num++;
        }
    }
    return num; 
}

int main(){

    int arr[] = {8,9,6,1,2,3,7,8,1,2,3,4,6,7};
    minSwap(arr, 14, 6);
    return 0;
}
