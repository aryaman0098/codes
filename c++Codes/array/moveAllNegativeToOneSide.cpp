#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void moveNegatives(int a[], int n){
    int positive = 0;
    for(int  i = 0; i < n; i++){
        if(a[i] < 0){
            swap(&a[i], &a[positive]);
            positive++;
        }
    }
}

void printArray(int a[], int n){
    for(int i = 0; i< n; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9 };
    moveNegatives(a, 9);
    printArray(a, 9);
}