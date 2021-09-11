#include<bits/stdc++.h>

using namespace std;

long long Count(long long arr[], long long left, long long mid, long long right){
    int l = mid - left + 1;
    int r = right - mid;
     
}

long long totalInversionCount(long long arr[], long long l, long long h){
    if(l >= h){
        return 0;
    }
    long long count;
    long long mid = l + (h - l) / 2;
    totalInversionCount(arr, l, mid);
    totalInversionCount(arr, mid + 1, h);
    count = Count(arr, l, mid, h);
}

long long inversionCount(long long arr[], long long N){
    long long n = totalInversionCount(arr, 0, N);
    return n;
}

int main(){

    return 0;
}
