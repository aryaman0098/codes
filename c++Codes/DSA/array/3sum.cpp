//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

#include<bits/stdc++.h>

using namespace std;

bool find3Numbers(int A[], int n, int X){
    int i, j, temp;
    sort(A, A + n);
    for(int k  = 0; k < n; k++){
        i = k + 1; j = n - 1;
        temp = X - A[k];
        while(i < j){
            if(A[i] + A[j] < temp){
                i++;
            }else if(A[i] + A[j] > temp){
                j--;
            }else{
                return true;
            }
        }
    }
    return false;
}

int main(){

    return 0;
}
