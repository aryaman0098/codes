//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include<bits/stdc++.h>

using namespace std;

void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l;
    for(int j = l; j <= r - 1; j++){
        if(arr[j] < pivot){
            swap(&arr[i], &arr[j]);
            ++i;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;

}

int kthSmallest(int arr[], int l, int r, int k){
    if(l < r){
        int pivot = partition(arr, l, r);
        if(k - 1 == pivot){
            return arr[k - 1];
        }else{
            (k - 1 > pivot) ? kthSmallest(arr, pivot + 1, r, k - pivot) : kthSmallest(arr, l, pivot - 1, k);
        }
    }
}

int main(){
    int arr[] = {10,80,30,90,40,50,70};
    cout<<kthSmallest(arr, 0, 6, 5);
    return 0;
}
