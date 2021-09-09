#include<bits/stdc++.h>

using namespace std;


int missingNumber(vector<int>& array, int n){
    int s = 0;
    for(int i = 0; i < n - 1; i++){
        s += array[i];
    }
    int sum = (n * (n + 1)) / 2;
    return (sum - s);
}