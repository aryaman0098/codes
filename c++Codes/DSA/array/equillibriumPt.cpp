//https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1#

#include<bits/stdc++.h>

using namespace std;

int equilibriumPoint(long long a[], int n){
    int mid = n / 2;
    int rightSum = 0, leftSum = 0;
    
    for(int i = 0; i < mid; i++){
        leftSum += a[i];
    }
    for(int i = mid + 1; i < n; i++){
        rightSum += a[i];
    }

    while(leftSum < rightSum){
        leftSum += a[mid];
        rightSum -= a[mid + 1];
        mid++;
    }
    while(leftSum > rightSum){
    leftSum -= a[mid];
    rightSum += a[mid - 1];
    mid--;
    }

    if(leftSum == rightSum){
        return mid;
    }else{
        return -1;
    }
}