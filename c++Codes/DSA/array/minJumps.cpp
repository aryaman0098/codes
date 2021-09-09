#include<bits/stdc++.h>

using namespace std;

int minJumps(int arr[], int n){
    int k;
    int numSteps;
    for(int i = 0; i < n; i++){
        k = i + arr[i];
        numSteps++;
        if(arr[k] > n - k - 1){
            numSteps++;
            return numSteps;
        }else{
            
        }
    }
}

int main(){

    return 0;
}
