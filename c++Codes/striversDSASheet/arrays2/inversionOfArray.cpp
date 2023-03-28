//https://www.codingninjas.com/codestudio/problems/count-inversions_615

#include <bits/stdc++.h>

using namespace std;

long long _merge(long long *arr, long long *temp, int low, int mid, int high) {
    int invCount=0;
    int i = low;
    int j = mid;
    int k = low;
    while((i <= mid-1) && (j <= high)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            invCount = invCount + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low ; i <= high ; i++)
        arr[i] = temp[i];
    
    return invCount;
}

long long mergeSort(long long *arr, long long *temp, int low, int high) {
    long long mid, invCount = 0;
    if(high > low) {
        mid = (low + high) / 2;

        invCount += mergeSort(arr, temp, low, mid);
        invCount += mergeSort(arr, temp, mid + 1, high);

        invCount += _merge(arr, temp, low, mid + 1, high);
    }
    return invCount;
} 

long long getInversions(long long *arr, int n){
    long long temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {

    return 0;
}