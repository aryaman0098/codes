//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

#include<bits/stdc++.h>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m){
    int gap = ((n + m) / 2) + ((n + m) % 2);
    while(gap > 0){
        for(int i = 0, j = gap; j < n + m; i++, j++){
            if(i < n && j < n){
                if(arr1[i] > arr1[j]){
                    swap(arr1[i], arr1[j]);   
                }
            }else if(i < n && (n <= j && j < n + m)){
                if(arr1[i] > arr2[j - n]){
                    swap(arr1[i], arr2[j - n]);   
                }
            }else if((n <= i && i < n + m) && (n <= j && j < n + m)){
                if(arr2[i - n] > arr2[j - n]){
                        swap(arr2[i - n], arr2[j - n]);   
                }
            }
        }
        gap = (gap <= 1) ? 0 : (gap / 2) + (gap % 2);
    }
}

int main(){
    int arr1[] = {7,9,9,10,11,11,13,14,17,19};
    int arr2[] = {1,1,4,5,8,11,13,16,19,19};
    merge(arr1, arr2, 10, 10);
    for(int i = 0; i < 10; i++){
        cout<<arr1[i]<<" ";
    }
    for(int j = 0; j < 10; j++){
        cout<<arr2[j]<<" ";
    }
    return 0;
}
