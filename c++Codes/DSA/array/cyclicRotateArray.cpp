#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void cyclicRotateArray(int a[], int n){
    for(int i = 0; i < n; i++){
        swap(&a[i], &a[n-1]);
    }
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[] = {2,1,4,2,5,9};
    cyclicRotateArray(a, 6);
    printArray(a, 6);
}