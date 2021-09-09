#include<bits/stdc++.h>

using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long max = INT_MIN;
    long long maxSoFar = 0;
    for(int i = 0; i < n; i++){
        maxSoFar += a[i];
        if(max < maxSoFar){
            max = maxSoFar;
        }
        if(maxSoFar < 0){
            maxSoFar = 0;
        }
    }
    return max;
}

int main(){

    return 0;
}
