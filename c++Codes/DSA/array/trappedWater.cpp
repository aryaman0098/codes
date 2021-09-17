//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include<bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n){
    vector<int> maxR;
    vector<int> maxL;
    int m1 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > m1){
            m1 = arr[i];
        }
        maxL.push_back(m1);
    }
    int m2 = INT_MIN;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > m2){
            m2 = arr[i];
        }
        maxR.push_back(m2);
    }    
    reverse(maxR.begin(), maxR.end());
    long long amount = 0;
    for(int i = 0; i < n; i++){
        amount += min(maxL[i], maxR[i]) - arr[i];
    }
    return amount;
}

int main(){ 
    int arr[] = {2,3,6,8,5};
    cout<<trappingWater(arr, 5);
    return 0;
}
