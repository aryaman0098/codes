//https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include<bits/stdc++.h>

using namespace std;

int smallestSubWithSum(int arr[], int n, int x){
    int i = 0, j = 0;
    int min = INT_MAX;
    int sum = arr[i];
    for(;j < n;){
        if(sum > x){
            cout<<i<<" "<<j<<"\n";
            if(min > j - i + 1){
                min = j - i + 1;
            }
            cout<<sum<<"\n";
            sum -= arr[i];
            i++;
        }else{
            j++;
            sum += arr[j]; 
        }if(i > j){
            j = i;
        }
    }
    return min;
}

int main(){
    int arr[] = {1,10,5,2,7};
    smallestSubWithSum(arr, 5, 9);
    return 0;
}
