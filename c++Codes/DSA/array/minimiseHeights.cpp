#include<bits/stdc++.h>

using namespace std;

void getMinDiff(int arr[], int n, int k){
    sort(arr, arr + n);
    arr[0] = arr[0] + k;
    for(int i = 1; i < n; i++){
        if(arr[i] - k >= 0){
            arr[i] = arr[i] - k;
        }else{
            arr[i] = arr[i] + k;
        }
    }
    int newmin = *max_element(arr, arr + n) - *min_element(arr, arr + n);
    cout<<newmin<<"\n";
}

int main(){
    int arr[] = {3, 9, 12, 16, 20};
    getMinDiff(arr, 5, 3);
}