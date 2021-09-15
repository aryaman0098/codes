//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

#include<bits/stdc++.h>

using namespace std;

long long maxProduct(vector<int> arr, int n){
    long long maxAtIndex = 1;
    long long minAtIndex = 1;
    long long max = INT_MIN;
    for long long i = 0; i < n; i++){
        if(arr[i] == 0){
            maxAtIndex = 1;
            minAtIndex = 1;
        }
        long long temp = maxAtIndex;
        maxAtIndex = (arr[i] > arr[i] * maxAtIndex) ? 
                     ((arr[i] > arr[i] * minAtIndex) ? arr[i] : arr[i] * minAtIndex) : 
                     ((arr[i] * maxAtIndex > arr[i] * minAtIndex) ? arr[i] * maxAtIndex : arr[i] * minAtIndex);
        minAtIndex = (arr[i] < arr[i] * temp) ? 
                     ((arr[i] < arr[i] * minAtIndex) ? arr[i] : arr[i] * minAtIndex) : 
                     ((arr[i] * temp < arr[i] * minAtIndex) ? arr[i] * temp : arr[i] * minAtIndex);
    
        if(max < maxAtIndex){
            max = maxAtIndex;
        }
    }
    return max;
}

int main(){

    return 0;
}
