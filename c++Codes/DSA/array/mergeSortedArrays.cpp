//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

#include<bits/stdc++.h>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m){
    int i = 0, j = 0;
    for(; i < n && j < m;){
        if(arr2[j] < arr1[i]){
            swap(arr1[i], arr2[j]);
            i++
        }else{
            j++;
            i++;
        }
    }
    int min = *min_element(arr2, arr2 + n);
    int max = *max_element(arr2, arr2 + n);

    while(i < m){

    }
}

int main(){

    return 0;
}
