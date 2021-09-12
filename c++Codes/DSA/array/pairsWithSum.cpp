//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

#include<bits/stdc++.h>

using namespace std;

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        m[k - arr[i]]++;
    }
    int count = 0;
    for(int j = 0; j < n; j++){
        count += m[arr[j]];
        if(k- arr[j] == arr[j]){
            count--;
        }
    }
    return count / 2;
}


int main(){

    return 0;
}
