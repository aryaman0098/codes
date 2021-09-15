//https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

#include<bits/stdc++.h>

using namespace std;

bool subArraysExists(int arr[], int n){
    unordered_set<int> u;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = arr[i];
        if(sum == 0 || u.find(sum) != u.end()){
            return true;
        }
        u.insert(sum);
    }
    return false;
}

int main(){

    return 0;
}
