//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include<bits/stdc++.h>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    int min = INT_MAX;
    for(int i = 0; i < n - m; i++){
        if(a[i + m] - a[i] < min){
            min = a[i + m] - a[i];
        }
    }
    return min;
}

int main(){

    return 0;
}
