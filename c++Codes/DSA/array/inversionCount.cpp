//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include<bits/stdc++.h>

using namespace std;

long long Count(long long arr[], long long left, long long mid, long long right){
    long long count = 0;
    long long temp[right - left + 1];
    long long k = 0, i = left, j = mid;
    for(; i < mid && j <= right;){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        if(arr[j] < arr[i]){
            temp[k] = arr[j];
            j++;
            k++;
            count += (mid - i);
        }
    }
    while(i < mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int a = left; a <= right; a++){
        arr[a] = temp[a - left];
    }

    return count;
}

long long totalInversionCount(long long arr[], long long l, long long h){
    if(l >= h){
        return 0;
    }
    long long count = 0;
    long long mid = (l + h) / 2;
    count += totalInversionCount(arr, l, mid);
    count += totalInversionCount(arr, mid + 1, h);
    count += Count(arr, l, mid + 1, h);

    return count;
}

long long inversionCount(long long arr[], long long N){
    long long n = totalInversionCount(arr, 0, N - 1);
    return n;
}

int main(){

    long long arr[] = {2,4,1,3,5};
    cout<<inversionCount(arr, 5)<<"\n";
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
