#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseArray(int a[], int n){
    for(int i = 0; i < n/2; i++){
        swap(&a[i], &a[n-i-1]);
    }
}

void printArray(int a[], int n){
    for(int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    reverseArray(a, n);
    printArray(a, n);
}